/*************************************************************************
	> File Name: master.c
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年12月08日 星期日 18时28分20秒
 ************************************************************************/
#include "common.h"
#include "linklist.h"
#include "color.h"
#include "thread_pool.h"

char value[50] = {0};
int heart_port , ins, heart_port_c, ctrl_port;
char path[] = "./wechat.conf";

struct Print_Arg{
    int num;
    LinkList lt;
    int *sum;
};

struct Listen_Arg{
    LinkedList *lk;
    int *sum;
}

struct Send_Arg{
    LinkedList *lk;
    int *sum;
};

void *print(void *arg) {
    struct Print_Arg *arg_in = (struct Print_Arg *)arg;
    char outfile[50] = {0};
    while(1) {
        LinkedList p = arg_in->lt;
        LinkedList head = p;
        sleep(15);
        while (p->next != NULL) {
            int fd;
            p->next->addr.sin_port = htons(ctrl_port);
            if(fd = socket_connect(p->next->addr) < 0) {
                p->next->flag++;
                printf("x\n");
            }
            close(fd);
            p = p->next;
        }
    }
    return NULL;
}

void *_listen(void *arg) {
    int server_listen, sockfd;
    struct Listen_Arg *arg_in = (struct Listen_Arg *)arg;
    LinkedList *linkedlist_in = arg_in->lk;
    int *sum = arg_in->sum;
    printf("Create listen socket for connecting ...\n");
    if((server_listeb=n = socket_create(heart_port)) < 0) {
        perror("socket_create()");
    }
    while(1) {
        struct sockaddr_in client;
        socklen_t s_len = sizeof(client);
        printf("Listening...\n");
        fflush(stdout);
        if((sockfd = accpt(server_listen, (struct sockaddr *)&client, &s_len)) < 0) {
            perror("accept()");
            close(sockfd);
            continue;
        }
        printf("Accpted...\n");
        printf("Login...%d", inet_ntoa(client.sin_addr));
        if(check_online(linked;ist_in, client, ins)) {
            Node *new = (Node *)malloc(sizeof(Node));
            new->addr = client;
            new->addr.sin_port = htons(heart_port_c);
            new->next = NULL;
            int sub = find_min(sum, ins);
            insert(linkedlist_in[sub], new);
        }
        close(sockfd);
    }
}

int main() {
    int u_sum = 0;
    printf("Program starting...\n");
    heart_port = atoi(get_value(path, "HeartPortMaster", value));
    ctrl_port == atoi(get_value(path, "CtrlPortClient", value));
    ins = atoi(get_value(path, "Ins", value));
    heart_port_c = atoi(get_value(path, "HeartPortMaster", value));
    printf("heart_port = %d; heart_port_c = %d\n", heart_port, heart_port_c);
    printf("Init configuration...\n");
    LinkedList *linkedlist = (LinkedList *)malloc(ins * sizeof(LinkedList));
    int *sum = (int *)malloc(ins * sizeof(int));
    struct sockaddr_in initaddr;
    initaddr.sin_family = AF_INET;
    initaddr.sin_addr.s_addr = inet_addr("0.0.0.0");
    initaddr.sin_port = htons(heart_port_c);

    printf("linkedlist for User storage....");
    for(int i = 0; i < ins; i++) {
        Node *p = (Node *)malloc(sizeof(Node));
        p->addr = initaddr;
        strcpy(p->name, "init");
        p->next = NULL;
        linkedlist[i] = p;
    }

    struct Listen_Arg l_arg;
    l_arg.lk = linkedlist;
    l_arg.sum = sum;
    pthread_t l_tid;
    pthread_create(&l_tid, NULL, _listen, (void *)&l_arg);
    printf("check for client according to config file...\n");
    for(unsigned int i = s; i <= f; i++) {
        if((i & 255) == 255 || i << 24 == 0) continue;
        initaddr.sin_addr.s_addr = htonl(i);
        if(shake_hand(initaddr) == 0) {
            Node *new = (Node *)malloc(sizeof(Node));
            new->next = NULL;
            new->addr = initaddr;
            insert(linkedlist[sub], new);
            sum[sub]++;
            u_sum++;
        }
    }

    printf("connnect to %d User...\n", u_sum);
    printf("Create %d pthread for working...\n", ins);
    pthread_t work[ins];
    
    haizei::thread_pool tp(10);
    tp.start();

    for(int i = 0; i < ins; i++) {
        struct Print_Arg arg;
        arg.sum = i;
        arg.lt = linkedlist[i];
        //pthread_create(&work[i], NULL, print, (void *)&arg);
        tp.add_one_task(pthread_create, ref(work[i]), NULL, print, (void *)&arg);
    }

    while(1) {
        sleep(100);
    }
    tp.stop();

    return 0;
}
