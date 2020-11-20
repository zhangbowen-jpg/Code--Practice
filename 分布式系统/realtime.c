/*************************************************************************
	> File Name: realtime.c
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月03日 星期一 15时47分29秒
 ************************************************************************/
#define _GNU_SOURCE
#include<sched.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
    cpu_set_t set;
    int ret, i;
    size_t cpuset_size;
    CPU_ZERO(&set);
    ret = sched_getaffinity(0, sizeof(cpu_set_t), &set);

    if(ret == -1)
        perror("get error");
    
    for(int i = 0; i < CPU_SETSIZE; i++) {
        int cpu;
        cpu = CPU_ISSET(i, &set);
        printf("cpu = %i is %s\n", i, cpu ? "set" : "unset");
    }



}


