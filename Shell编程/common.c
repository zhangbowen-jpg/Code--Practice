/*************************************************************************
	> File Name: common.c
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月05日 星期二 19时23分10秒
 ************************************************************************/
#include<stdio.h>


int shake_hand(struct sockaddr_in host, char *name) { 
    //处在阻塞状态直接跳过
    int sockfd;
    struct timeval tm;
    if((sockfd = socket_()) < 0) {
        return -1; 
    } //空白套接字
    
    unsigned long len = 1;
    ioctl(sockfd, FIONBIO,&len);  //将文件改成非阻塞IO
   

    FD_ZORE(&wfds);
    FD_SET(socked, &wfds);
    tm.tv_sec = 0;
    tm.tv_usec = 1000;
    int error = -1;
        
    if(connect(sockfd, (struct sockaddr *)&host, sizeof(host)) < 0) {
        if (select(sockfd + 1, NULL, &wfds, NULL, &tm) > 0) {
            getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &error, (socklen_t*)&len);
            if(error != 0) return -1;
            send(sockfd, name, strlen(name), 0);
            memset(name, 0, sizeof(name));
            recv(name, 0, sizeof(name), 0);
        } else {
            return -1;
        }
    }
    close(sockfd); 
    return 0;
}

int find_min(int *sum, int ins) {
    for(int i = 0; i < ins; i++) {
        if(*(sum + i) < *(sum + sub)) sub = i;
    }
    return sub;
}

bool check_online(LinkedList *head, struct sockaddr_in client, int ins) {
    for (int i = 0; i < ins; i++) {
        Node *p = head[i];
        while (p->next != NULL) {
            if(p->next->addr.sin_addr.s_addr == client.sin_addr.s_addr) {
                return false;
            }
            p = p->next;
        }
    }
    return true;
}

