/*************************************************************************
	> File Name: exec.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月11日 星期五 09时46分44秒
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#define MAX_PATH 64

int main(int argc,char **argv) {
    pid_t pid;
    char filename[512] = {0};
    char name[512] = {0};
    char tmp[5] = {0};
    char cc_flag[50] = {0};
    char buffer[MAX_PATH];
    char *canshu; 
        if(argc < 2) {
        printf("argc error\n");
        exit(1);
    }
    strcpy(filename, argv[1]); //文件名拷贝
    
    char *sub;
    
    sub = strstr(filename,"."); //从哪里开始找。
    strncpy(name, filename, sub - filename);  //复制除了后缀的文件名,sub-filename表示中间的字符
    strcpy(tmp, sub); //后缀

    printf("%s\n", tmp);
    if(!strcmp(tmp, ".c")) {
        strcpy(cc_flag, "gcc"); //编译命令
    } else if (!strcmp(tmp, ".cpp")) {
        strcpy(cc_flag, "g++");
    } else {
        printf("Not Support File Type\n");
        exit(2);
    }
    if((pid = fork()) < 0) {
        perror("fork");
        exit(3);
    }
    if(pid == 0) {
        execlp("/usr/bin/vim", "vim" , filename, NULL); //打开vim
    }
    sleep(3);
    if((pid = fork()) < 0) {
        perror("fork");
        exit(4);
    }
    if(pid == 0) {
        execlp(cc_flag ,cc_flag, filename, "-o", name, NULL); //编译
    }
    if((pid = fork()) < 0) {
        perror("fork");
        exit(5);
    }
    if(pid == 0){
        getcwd(buffer,MAX_PATH); //获得当前路径
        if(argc >= 3) {
            for(int i = 3; i <= argc; i++) {
                canshu = argv[i - 1];
            }
        }
        else canshu = NULL;
        strcat(buffer,"/");
        strcat(buffer,name); //这是最难的，凑字符串。。。
        char env[MAX_PATH] = {"./"};
        strcat(env, name);
        execl(buffer, env, canshu, NULL);
    }
    wait(NULL);
    return 0;
}

