/*************************************************************************
	> File Name: common.c
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月08日 星期五 23时53分48秒
 ************************************************************************/

#include "common.h"


char *get_value(char *path, char *key, char *ans) {
    FILE *fp = NULL;
    ssize_t read;
    size_t len;
    char *line = NULL;
    char *substr = NULL;

    if(key == NULL || ans == NULL || path == NULL) {
                printf("Error in argument\n");
                return NULL;
    }

    if((fp = fopen(path, "r")) == NULL) {
                perror("fopen");
                return NULL;
    }
    
        while((read = getline(&line, &len, fp)) != -1) {
                if((substr = strstr(line, key)) == NULL) 
                    continue;
                else {
                    if(substr[strlen(key)] == '=') {
                        strncpy(ans, substr + strlen(key) + 1, read - strlen(key) - 1);
                        *(ans + strlen(ans) - 1) = '\0';
                        break;
                    }
                }
        }
            free(line);
            fclose(fp);

        if(substr == NULL) {
                return NULL;
        }

        return ans;
}

int socket_() {
        int sockfd;
        if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                perror("socket_()");
                return -1;
        }
        return sockfd;
}

int socket_create(int port) {
    int sockfd;
    int yes = 1;
    struct sockaddr_in sock_addr;

    struct linger m_sLinger;
    m_sLinger.l_onoff = 1;
    m_sLinger.l_linger = 0;

    //创建套接字
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket() error");
        return -1;
    }

    //设置本地套接字地址
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(port); //转化为网络字节序
    sock_addr.sin_addr.s_addr = htonl(INADDR_ANY); // 0.0.0.0

    //设置本地套接字
    setsockopt(sockfd, SOL_SOCKET, SO_LINGER, (const char*)&m_sLinger, sizeof(struct linger));

    if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        close(sockfd);
        perror("setsockopt() error\n");
        return -1;
    }

    //绑定本地套接字的套接字
    if(bind(sockfd, (struct sockaddr *) &sock_addr, sizeof(sock_addr)) < 0) {
    close(sockfd);
        perror("bind() error");
        return -1;
    }
    
    //将套接字设置为监听状态
    if(listen(sockfd, 20) < 0) {
        close(sockfd);
        perror("listen() error");
        return -1;
    }
    return sockfd;
}



int shake_hand(struct sockaddr_in host, char *name) {
    
    //Data user = (Data *)malloc(sizeof(Data));

    int sockfd;

    if((sockfd = socket_()) < 0) {
        return 0;
    }
    
    fd_set set;

    unsigned long len = 1;
    ioctl(sockfd, FIONBIO, &len);
    FD_ZERO(&set);
    FD_SET(sockfd, &set);
    struct timeval tm;
    tm.tv_sec = 0;
    tm.tv_usec = 10000;
    int error = -1;
    int len_t = sizeof(int);

    if(connect(sockfd, (struct sockaddr *)&host, sizeof(host)) < 0) {
        int len = sizeof(int);
        if(select(sockfd + 1, NULL, &set, NULL, &tm) > 0) { //在时间内套接字可写
            getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &error, (socklen_t*)&len_t);    
            if(error != 0) {
                close(sockfd);
                return -1;
            }
            send(sockfd, name, strlen(name), 0);
        } else {
            close(sockfd);
            return 0;
        }
    }
    close(sockfd);
    return 1;
}

int find_min(int *sum, int ins) {
    int ans = 0;
    for(int i = 0; i < ins; i++) {
        if(*(sum + i) < *(sum + ans))
            ans = i;
    }
    return ans;
}

bool check_online(LinkedList *head, struct sockaddr_in client, int ins) {
    for(int i = 0; i < ins; i++) {
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


