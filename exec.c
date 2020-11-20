/*************************************************************************
	> File Name: exec.c
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月23日 星期三 18时09分35秒
 ************************************************************************/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char **argv) {
    pid_t pid;
    char filename[512] = {0};
    char name[512] = {0};
    char tmp[10] = {0}; // 提取后缀
    char cc_flag[50] = {0};  //存放命令

    if(argc != 2) {
        printf("Usage: ./a.out condefile\n");
        exit(1);
    }
    strcpy(filename, argv[1]);

    char *sub;
    
    sub = strstr(filename, ".");
    strncpy(name, filename, sub - filename); //提取名字到name中
    strcpy(tmp, sub);

    if(!strcmp(tmp, ".c")) {
        strcpy(cc_flag, "gcc");
    } else if (strcmp(tmp, ".cpp")) {
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
        execlp("/user/bin/vim", "vim", filename, NULL);
    }
    
    wait(NULL);
    
    return 0;
}


