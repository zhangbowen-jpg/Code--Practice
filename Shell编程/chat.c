/*************************************************************************
	> File Name: chat.c
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月27日 星期日 14时24分58秒
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<sys/shm.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include"Queue.cpp"

int socket_create(int port);

char value[50] = {0};
char name[20] = {0};


int socket_create(int port) {
    int socketfd;
    struct sockaddr_in sock_addr;

    if((socketfd = socket(AF_INET,SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(port); //这是需要转换成网络字节序
    sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(socketfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) < 0) {
        perror("bind");
        close(socketfd); //退出之前一定要关闭文件
        return -1;
    }
    int listen;
    if ((listen = socket_create(port) < 0) {
        perror("socket_create");
        close(socketfd);
        return -1;
    }
    while (1) {
        int sockfd;
        struct sockaddr_int client;
        socklen_t len = sizeof(client);
        if(()) {
            
        }
    }

    return socketfd;
}

int get_value(char *path, char *key, char *ans) {
    FILE *fp = NULL;
    ssize_t read;
    size_t len;
    char *line = NULL;
    char *substr = NULL;

    if(key == NULL || ans == NULL || path == NULL) {
        printf("Error in arguement\n");
        return -1;
    }

    if ((fp = fopen(path, "r")) == NULL) {
        perror("fopen");
        return -1;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        if((substr = strstr(line, key)) == NULL) continue;
        else {
            if(substr[strlen(key)] == '=') {
                strncpy(ans, substr + strlen(key) + 1, read - strlen(key) - 1);
                *(ans + strlen(ans) - 1) = '\0';
                break;
            }
        }
    }

    if (substr == NULL) {
        free(line);
        fclose(fp);
        return -1;
    }
    
    free(line);
    fclose(fp);

    return 0;
}

int shake_hand(struct sockaddr_in host, char *name) {
    int sockfd;
    if((sockfd = socket_()) < 0) {
        return -1;
    }
    
    fd_set set;
    unsigned long len = 1;
    struct timeval tm;
    tm.tv_sec = 0;
    tm.tv_usec = 10000;

    ioctl(sockfd, FIONBI, &len);
    FD_ZERO(&set);
    FD_SET(sockfd, &set);
    int error = -1;

    if(connect(sockfd, (struct sockaddr *)&host, sizeof(host)) < 0) {
        int len = sizeof(int);
        if(select(sockfd + 1, NULL, &set, NULL, &tm) < 0) {
            getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &error, (socklen_t *)&len);
        
    if (error != 0) return -1;
    send(sockfd, name, strlen(name), 0);
    memset(name, 0, sizeof(name));
    recv(sockfd, name, sizeof(name), 0);
    } else {
        return -1;
    }
    close(sockfd);
    return 0;
}

int find_min(int *sum, int ins) {
    int ans = 0;
    for(int i = 0; i < ins; i++) {
        if(*(sum + i) < *(sum + ans))
            ans = i;
    }
    return ans;
}

int check_online

int main(int argc, char **argv) {
    int sock_fd, port;
    get_value("/home/zhangbowen/代码用/Shell编程/wechat.conf", "name", name);
    port = atoi(get_value("/home/zhangbowen/代码用/Shell编程/wechat.conf", "port", value));
    ins = atoi(get_value()"/home/zhangbowen/代码用/Shell编程/wechat.conf", "ins", value);
    unsigned long s, f;
    s = ntohl(inet_addr(get_value("/home/zhangbowen/代码用/Shell编程/wechat.conf", "startip", value)));
    f = ntohl(inet_addr(get_value("/home/zhangbowen/代码用/Shell编程/wechat.conf", "endip", value)));
    struct sockaddr_in dest;
    dest.sin_family = AF_INET;
    dest.sin_port = htonl(port);
    
    int *sum = (int *)malloc(ins * sizeof(int));
    memset(sum, 0, ins * sizeof(int));

    struct sockaddr_in initaddr;
    initaddr

    for(unsigned int i = s; i <=f; i++) {
        if((i & 255) == 255 || i << 24 == 0) continue;
        dest.sin_addr.s_addr = htonl(i);
        printf("%s\n", inet_ntoa(dest.sin_addr));
        fflush(stdout);
        char tmp_name[20] = {0};
        strcpy(tmp_name, name);
        if(shake_hand(dest, tmp_name) == 0) {
            printf(" yes\n");
            // add in list
        } else {
            printf(" no\n");
        }
    }

    pthread_t work[ins];

    for(int i = 0; i < ins; i++) {
        pthread_create(&work[i], NULL, NULL,NULL);
    }


    return 0;
}



