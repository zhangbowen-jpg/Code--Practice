/*************************************************************************
	> File Name: fork.c
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月23日 星期三 17时00分10秒
 ************************************************************************/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main() {
    pid_t pid;
    int status;
    
    pid = fork();
    if(pid == 0) {
        printf("Child : %d -> %d \n", getpid(), getppid());
        exit(2);
    } else {
        wait(&status);
        printf("Father : %d, [%d] \n", getpid(),status);
    }

    return 0;
}

