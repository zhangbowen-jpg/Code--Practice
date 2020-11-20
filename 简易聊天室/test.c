/*************************************************************************
	> File Name: test.c
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月09日 星期六 01时36分28秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int listenfd, sockfd;
    sockfd = socket_create(8888);
    struct sockaddr_in client;
    socklen_t len = sizeof(client)'
    while(1) {
        if((sockfd = accept(listenfd, (struct sockaddr *)&client, &len) < 0)) {
        perror("accept");
        continue;
        }
        struct Msg msg;
        recv(sockfd, (char *)&msg, sizeof(msg), 0);
        if(msg.type == 0 && msg.size == 0) {
            D("["L_GRENN"Accept"NONE"] %s : %s \n", msg.name, inet_ntoa(client.sin_addr));
            strcpy(msg.name, "suyelu");
            send(sockfd, &msg, sizeof(msg), 0);
            close(sockfd);
        } else if (msg.type == 1 && msg.size == 0) {
            D("["RED"HeartBeat"NONE"] : %s->%s\n", msg.name, inet_ntoa(client.sin_addr));
            close(sockfd);
        } else if (msg.type == 2 && msg.size != 0) {
            D("["PINK"UserData"NONE"] : %s->%s\n", msg.name, inet_ntoa(client.sin_addr));
            close(sockfd);
        } else {
            D("["L_RED"Error"NONE"] : %s->%s\n", msg.name, inet.ntoa(client.sin_addr));
            close(sockfd);
        }
    }
}

