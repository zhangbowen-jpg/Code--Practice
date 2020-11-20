/*************************************************************************
	> File Name: ls1.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年09月21日 星期六 20时54分16秒
 ************************************************************************/
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<dirent.h>
#include<grp.h>
#include<pwd.h>
#include<time.h>
#include<unistd.h>
#define NAME_SIZE 20

struct fnode
{
    struct fnode *next ; //下一个成员
    char name[NAME_SIZE] ; //当前成员文件名
} ;

struct fnode* insert_list(struct fnode *node , struct fnode *linklist) ; //将节点插入链表中

void output_info(struct fnode *head) ; //输出文件信息

void output_type_perm(mode_t mode) ; //列出文件的权限和类型字符

void output_user_group(uid_t uid , gid_t gid) ; //列出用户及用户信息

void output_mtime(time_t mytime) ; //列出各文件基本信息

void myfree(struct fnode *linklist) ; //释放内存

int main(int argc , char* argv[])
{
    if(argc < 2)
    {
        printf("usage : %s dir_name \n" , argv[0]) ;
        exit(EXIT_FAILURE) ;
    }

    int i ;
    for(i = 1 ; i < argc ; i++)
    {
        struct fnode *linklist = NULL ;
        struct stat stat_info ;

        if(stat(argv[i] , &stat_info) == -1)
        {
            perror("stat") ;
            exit(EXIT_FAILURE) ;
        }

        printf("argv[i] is : %s \n" , argv[i]) ;

        if(S_ISREG(stat_info.st_mode)) //普通文件
        {
            printf("It is a normal file\n") ;
            struct fnode *temp = (struct fnode*) malloc(sizeof(struct fnode)) ; //为当前文件结构申请内存空间

            if(temp == NULL)
            {
                perror("malloc error") ;
                exit(EXIT_FAILURE) ;
            }
            temp->next = NULL ;

            //将当前文件名拷贝到temp->name中
            memset(temp->name , '\0' , NAME_SIZE) ;
            memcpy(temp->name , argv[i] , strlen(argv[i])) ;
            linklist = insert_list(temp , linklist) ; //将该文件插入linklist中
            output_info(linklist) ; //输出文件的所有信息
        }
        else if(S_ISDIR(stat_info.st_mode)) //是否是路径
        {
            printf("It is a dir \n") ;

            char buf[NAME_SIZE] ; 
            getcwd(buf , 128) ; //获取当前工作路径并将其拷贝到buf中
            DIR *dirp = NULL ;
            dirp = opendir(argv[i]) ; //打开当前路径
            if(dirp == NULL)
            {
                perror("open dir") ;
                exit(EXIT_FAILURE) ;
            }
            struct dirent *entp = NULL ;
            while(entp = readdir(dirp))
            {
                struct fnode *temp = (struct fnode *)malloc(sizeof(struct fnode)) ;
                if(temp == NULL)
                {
                    perror("malloc") ;
                    exit(EXIT_FAILURE) ;
                }
                temp->next = NULL ;
                memset(temp->name , '\0' , NAME_SIZE) ;
                memcpy(temp->name , entp->d_name , strlen(entp->d_name)) ;
                linklist = insert_list(temp , linklist) ;
            }
            chdir(argv[i]) ; //改变当前路径
            closedir(dirp) ;
            output_info(linklist) ;
            chdir(buf) ;
        }
        myfree(linklist) ;
    }
    return 0 ;
}       

void output_type_perm(mode_t mode)
{
    char type[7] = {'p' , 'c' , 'd' , 'b' , '-' , 'l' , 's'} ;
    int index = ((mode >> 12) & 0xF) / 2 ;
    printf("%c" , type[index]) ;

    char *perm[8] = {"---" , "--x" , "-w-" , "-wx" , "r--" , "r-x" , "rw-" , "rwx"} ;
    printf("%s" , perm[mode >> 6 & 07]) ;
    printf("%s" , perm[mode >> 3 & 07]) ;
    printf("%s" , perm[mode >> 0 & 07]) ;
}

void output_user_group(uid_t uid , gid_t gid)
{
    struct passwd *user ;
    user = getpwuid(uid) ;

    printf(" %s" , user->pw_name) ;

    struct group *group ;

    group = getgrgid(gid) ;
    printf(" %s" , group->gr_name) ;
}

void output_mtime(time_t mytime)
{
    char buf[256] ;
    memset(buf , '\0' , 256) ;
    ctime_r(&mytime , buf) ;
    buf[strlen(buf) - 1] = '\0' ;
    printf(" %s" , buf) ;
}

void output_info(struct fnode *head)
{
    struct fnode *temp = head  ;
    while(temp != NULL)
    {
        struct stat mystat ;
        if(stat(temp->name , &mystat) == -1)
        {
            perror("stat") ;
            exit(EXIT_FAILURE) ;
        }
        output_type_perm(mystat.st_mode) ;
        printf(" %4d" , mystat.st_mode) ;
        output_user_group(mystat.st_uid , mystat.st_gid) ;
        printf(" %8ld" , mystat.st_size) ;
        output_mtime(mystat.st_mtime) ;
        printf(" %s\n" , temp->name) ;
        temp = temp->next ;
    }
}

struct fnode * insert_list(struct fnode* temp , struct fnode * linklist)
{
    if(linklist == NULL)
    {
        linklist = temp ;
    }
    else
    {
        struct fnode *node ;
        node = linklist ;
        while(node->next != NULL)
        {
            node = node->next ;
        }
        node->next = temp ;
    }
    return linklist ;
}

void myfree(struct fnode *linklist)
{
    struct fnode *temp ;
    temp = linklist ;
    while(temp != NULL)
    {
        temp =  linklist->next ;
        free(linklist) ;
        linklist = temp ;
    }
}

