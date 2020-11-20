/*************************************************************************
	> File Name: hmcommon.h
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月26日 星期六 14时13分28秒
 ************************************************************************/
#ifndef _HMCOMMON_H
#define _HMCOMMON_H
#endif

#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>

struct Msg {
    char message[50];
    pthread_mutex_t mutex;
    pthread_mutexattr_t m_attr;
    pthread_cond_t cond;
    pthread_condattr_t c_attr;
};

void *get_shm(char *path, int id, int *shmid) { //传入一个地址
    char *share_memory = NULL;
    
key_t key = ftok(path, id);

if((*shmid = shmget(key, sizeof(struct Msg), IPC_CREAT | 0600)) < 0) {
    perror("shmget");
}

if((share_memory = shmat(*shmid, NULL, 0)) == NULL) {
    perror("shmat");
}
return share_memory;                              

}
