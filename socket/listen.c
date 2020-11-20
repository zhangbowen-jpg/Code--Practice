/*************************************************************************
	> File Name: listen.c
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月27日 星期日 16时17分05秒
 ************************************************************************/
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void listen() {
    int port, socketfd, listen;
    port = 8888;
    struct sockaddr_in client_addr;
    socklen_t len = sizeof(client_addr);
    while(1) {
    if ((sockfd = accept(server_listen, (struct sockaddr *)&client_addr, &len)) < 0) {
            perror("accept");
            continue;
    }
}

int main() {
    

}
