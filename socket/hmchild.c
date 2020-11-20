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
    msg = (struct Msg *)get_shm("/home/zhangbowen/代码用/Shell编程/", 8733, &shmid);

    if(msg == NULL) {
        exit(1);
    }
  
    while(1) {
        pthread_mutex_lock(&msg->mutex);
        printf("<child> : ");
        scanf("%s", msg->message);
        pthread_mutex_unlock(&msg->mutex);
        pthread_cond_signal(&msg->cond);
        usleep(20);
    }

    return 0;

}


