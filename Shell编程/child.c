/*************************************************************************
	> File Name: child.c
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月25日 星期五 12时31分36秒
 ************************************************************************/

#include "head.h"

struct Msg {
    pid_t pid;
    char message[1024];
};

void *share_memory = NULL;

int main() {
    int shmid;
    key_t key = ftok("/home/zhangbowen/代码用/Shell编程/", 8731);
    
    if((shmid = shmget(key, sizeof(struct Msg), IPC_CREAT | 0644)) < 0) {
        perror("shmget");
    }
        
    if((share_memory = shmat(shmid, NULL, 0)) < 0) {
        perror("shmat");
    }
    
    struct Msg *msg = (struct Msg *)share_memory;

    while(1) {
        scanf("%s",msg->message);
        kill(msg->pid, 10);
    }
    
    return 0;
}

