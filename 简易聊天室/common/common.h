/*************************************************************************
	> File Name: common.h
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月conflicting types for ‘check_online’08日 星期五 22时34分10秒
 ************************************************************************/
#include "head.h"
#ifndef _COMMON_H
#define _COMMON_H

char *get_value(char *path, char *key, char * const ans);

int socket_create(int port);

int socket_();

int shake_hand(struct sockaddr_in host, char *name); //传入socked_in结构体和自己的名字

int find_min(int *sum, int ins);

bool check_online(LinkedList *head, struct sockaddr_in client, int ins);

#endif
