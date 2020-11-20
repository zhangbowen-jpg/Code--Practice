/*************************************************************************
	> File Name: wechat.c
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月09日 星期六 00时36分20秒
 ************************************************************************/
#include "head.h"
#include "common.h"
#include "linklist.h"

char value[50] = {0};
char name[20] = {0};
int port, ins;
char path[] = "./wechat.conf";

/*
void *change_list(void *arg) {
    LinkedList num = (LinkedList *)arg;
    int sum = 0;
    if(num->next != NULL) {
        sum++;
        if(num->next == linkedlist->next) continue;
        else insert(linklist[sum], head[sum]);
    }
    num = num->next;
}
 */
void add_usr(struct sockaddr_in *s, int *sum, LinkedList *linkedlist) {
    if (check_online(linkedlist, *s, ins)) {
        Node *new = (Node *)malloc(sizeof(Node));
        new->addr = *s;
        new->addr.sin_port = htons(port); //端口是对方的，要改
        new->next = NULL;
        if (shake_hand(*s, name) != 0) {
            return ;
        }
        strcpy(new->name, name);
        int sub = find_min(sum, ins);
        insert(linkedlist[sub], new);
        sum[sub++];
    }
}

void *print(void *arg) {
    while(1) {
        LinkedList p = (LinkedList)arg;
        sleep(10);
        printf("print:\n");
        while(p->next != NULL) {
            printf("%s_%s\n", inet_ntoa(p->next->addr.sin_addr), p->next->name);
            p = p->next;
        }
    }
    
    return NULL;
}


int main() {
    get_value(path, "name", name);
    port = atoi(get_value(path, "listenport", value));
    ins = atoi(get_value(path, "ins", value));

    unsigned int s, f;
    s = ntohl(inet_addr(get_value(path, "startip", value)));
    f = ntohl(inet_addr(get_value(path, "endip", value)));

   
    int *sum = (int *)malloc(ins * sizeof(int));

    LinkedList *linkedlist = (LinkedList *)malloc(ins * sizeof(LinkedList));
    
    struct sockaddr_in initaddr;
    initaddr.sin_family = AF_INET;
    initaddr.sin_addr.s_addr = inet_addr("0.0.0.0");
    initaddr.sin_port = htons(port);

    for(int i = 0; i < ins; i++) {
        Node *p = (Node *)malloc(sizeof(Node));
        p->addr = initaddr;
        p->len = 0;
        strcpy(p->name, "init");
        p->next = NULL;
        linkedlist[i] = p;
    }
    D("before init!\n");
    for(unsigned int i = s; i <= f; i++) {
        if((i & 255) == 255 || i << 24 == 0) continue;
        initaddr.sin_addr.s_addr = htonl(i);
        char tmp_name[20] = {0};
        strcpy(tmp_name, name);
        if(shake_hand(initaddr, tmp_name) == 0) {
            Node *New = (Node *)malloc(sizeof(Node));
            New->heart = 0;
            New->next = NULL;
            New->addr = initaddr;
            strcpy(New->name, tmp_name);
            int sub = find_min(sum, ins);
            insert(linkedlist[sub], New);
            sum[sub]++;
        }
    }
    
    D("create work pthread\n");
    //创建作业线程
    
    pthread_t work[ins];
    for(int i = 0; i < ins; i++) {
        pthread_create(&work[i], NULL, print, (void *)linkedlist[i]);
    }

    //在这实现交换用户表
/*    pthread_t change_list;
    for(int i = ; i < ins; i++) {
        pthread_create(&change_list, NULL, change, (void *)linkedlist[i]);
    }
    */
    //创建监听线程

    int listen;
    if((listen = socket_create(port)) < 0) {
        perror("socket_create()");
        return 1;
    }

    while(1) {
        int sockfd;
        struct sockaddr_in client;
        socklen_t len = sizeof(client);
        D("Listening..\n");
        fflush(stdout);
        if((sockfd = accept(listen, (struct sockaddr *)&client, &len)) < 0) {
            perror("accept()");
            close(sockfd);
            continue;
        }
        
        fd_set set;
        FD_ZERO(&set);
        FD_SET(sockfd, &set);

        struct timeval tv;
        tv.tv_sec = 0;
        tv.tv_usec = 10000;
        char logname[20] = {0};
        if(select(sockfd + 1, &set, NULL, NULL, &tv) > 0) {
            if(FD_ISSET(sockfd, &set)) {
                Msg *data = (Msg *)malloc(sizeof(Msg));
                recv(sockfd, data, sizeof(Msg), 0);
                if (data->type == 1) {
                    printf("%s\n", data->name);
                    close(sockfd);
                    continue;
                } else if (data->type == 2) {
                    int num = data->size / sizeof(struct sockaddr_in);
                    struct sockaddr_in *s = (struct sockaddr_in*)malloc(data->size);
                    int now = 0;
                    while (recv(sockfd, &s[now++], sizeof(struct sockaddr_in), 0) != 0); //单个sockaddr_in接收同时计数
                    if (now != num) {
                        close(sockfd);
                        continue;
                    }
                    for (int i = 0; i < num; i++) {
                        add_usr(&s[i], sum, linkedlist);
                    }
                    close(sockfd);
                    continue;
                } else if (data->type == 0) {
                    strcpy(logname, data->name);
                    strcpy(data->name, name);
                    data->size = 0;
                    send(sockfd, data, sizeof(Msg), 0);
                    if (check_online(linkedlist, client, ins)) {
                         Node *new = (Node *)malloc(sizeof(Node));
                         new->addr = client;
                         new->addr.sin_port = htons(port); //端口是对方的，要改
                         new->next = NULL;
                         new->heart = 0;
                         strcpy(new->name, logname);
                         int sub = find_min(sum, ins);
                         insert(linkedlist[sub], new);
                    }
                     close(sockfd);
                } else {
                    continue;
                }
            } else {
                close(sockfd);
                continue;
            }
        } else {
            close(sockfd);
        }
    }
    return 0;
}
