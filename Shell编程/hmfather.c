/*************************************************************************
	> File Name: hmfather.c
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月26日 星期六 14时41分54秒
 ************************************************************************/

#include "hmcommon.h"

struct Msg *msg;

int main() {
    int shmid;
    msg = (struct Msg *)get_shm("/home/zhangbowen/代码用/Shell编程/",8733, &shmid);

    if(msg == NULL) {
        exit(1);
    }

    pthread_mutexattr_init(&msg->m_attr);
    pthread_mutexattr_setpshared(&msg->m_attr, PTHREAD_PROCESS_SHARED);
    pthread_condattr_init(&msg->c_attr);
    pthread_condattr_setpshared(&msg->c_attr,PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&msg->mutex, &msg->m_attr);
    pthread_cond_init(&msg->cond,&msg->c_attr);

    while(1) {
        pthread_mutex_lock(&msg->mutex); 
        printf("sleeping 10s..\n");
        sleep(10);
        printf("In Mutex, cond waitting..\n");
        pthread_cond_wait(&msg->cond, &msg->mutex);
        printf("%s\n", msg->message);
        pthread_mutex_unlock(&msg->mutex);
    }

    return 0;

}


