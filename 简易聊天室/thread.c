/*************************************************************************
	> File Name: thread.c
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月26日 星期六 19时00分54秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t t[15];
int id[15];

void *print(void *argv) {
    int *tmp = (int *)argv;
    sleep(rand()%11);
    printf("<%d> : %lu %lu\n", *tmp, pthread_self(), (void *)t[*tmp]);
    return NULL;
}

int main() {
    for(int i = 1; i <= 10; i++) {
        pthread_create(t[i], pthread_self(), print, (void *)id[i]);

    }
    for(int i = 1; i <= 10; i++) {
        pthread_join(t[i], (void *)id[i]);
    }
    return 0;
}

