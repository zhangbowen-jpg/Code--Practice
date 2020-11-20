/*************************************************************************
	> File Name: common.h
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年12月08日 星期日 18时08分50秒
 ************************************************************************/
#include "head.h"
#ifndef _COMMON_H
#define _COMMON_H

char *get_value(char *path, char *key, char * const ans);

int socket_create(int port);

int socket_();

int socket_connect_ip(int port,char *name);

int shake_hand(struct sockaddr_in host, char *name); //传入socked_in结构体和自己的名字

int find_min(int *sum, int ins);

bool check_online(LinkedList *head, struct sockaddr_in client, int ins);

bool check_body(void *arg, void *arg1);

int *change_list(void *arg);

#endif
