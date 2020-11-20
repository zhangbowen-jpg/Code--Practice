/*************************************************************************
	> File Name: shmv1.c
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月25日 星期五 10时40分29秒
 ************************************************************************/

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h> 
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>

char *share_memory = NULL;                //共享内存

void *print() {
    printf("<Father> : %s\n", share_memory);
    return NULL;
}


int main() {
    int shmid;
    pid_t pid;
    key_t key = ftok(".", 8731);
    
    if((shmid = shmget(key, 4096,IPC_CREAT | 0666)) < 0) {  //0666为权限，全体可读写
        perror("shmget");
        exit(1);
    }
    //必须判断内存分配是否成功，因为存在失败的可能，所以要判断
    if((share_memory = shmat(shmid, NULL, 0)) < 0) {
        perror("shmat");
        exit(1);
    }
        
    if((pid = fork()) < 0) {
        perror("fork()");
        exit(1);
    }
    if(pid == 0) {
        while(1) {
            printf("<child> : ");
            scanf("%s", share_memory);
            kill(getppid(), 10); //将10信号发送给它的父进程
        }
    } else {
        while (1) {
            signal(10 ,print);
            pause();
        }
    }

    return 0;
}



