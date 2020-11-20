/*************************************************************************
	> File Name: head.h
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月08日 星期五 22时27分52秒
 ************************************************************************/
#ifndef _HEAD_H
#define _HEAD_H

#include<arpa/inet.h>
#include<ctype.h>
#include<dirent.h>
#include<errno.h>
#include<fcntl.h>
#include<netdb.h>
#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>
#include<signal.h>
#include<sys/socket.h>
#include<stdarg.h>
#include<pwd.h>
#include<sys/epoll.h>
#include<string.h>
#include<sys/ioctl.h>
#include<sys/time.h>
#include<sys/stat.h>
#include<stdbool.h>
#include<sys/file.h>
#include<sys/epoll.h>

typedef struct Node {
    int len;
    int heart;
    struct Node *next;
    struct sockaddr_in addr;
    char name[20];
}Node, *LinkedList;



typedef struct Msg {
    int type;
    int size;
    char name[20];
}Msg;


#ifdef _DEBUG
#define D(fmt, args...) printf(fmt, ##args)
#else
#define D(fmt, args...)
#endif

#endif
