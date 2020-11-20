/*************************************************************************
	> File Name: father.c
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月25日 星期五 12时01分33秒
 ************************************************************************/

#include "head.h"

struct Msg {
    pid_t pid;
    char message[1024];
};

void *share_memory = NULL;

struct Msg *msg; 

void print() {
    printf("%s\n", msg->message);
}

int main() {
    int shmid;
    signal(10, print);
    key_t key = ftok("/home/zhangbowen/代码用/Shell编程/", 8731);
    
    if((shmid = shmget(key, sizeof(struct Msg), IPC_CREAT | 0644)) < 0) {
        perror("shmget");
    }
        
    if((share_memory = shmat(shmid, NULL, 0)) < 0) {
        perror("shmat");
    }
    
    msg = (struct Msg *)share_memory;

    msg->pid = getpid();

    

    while(1) {
        pause();
    }
    
    return 0;
}




