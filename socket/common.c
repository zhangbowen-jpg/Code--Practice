/*************************************************************************
	> File Name: common.c
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月24日 星期四 09时42分22秒
 ************************************************************************/
#include"common.h"


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
    
    if(listen(socketfd, 20) < 0) {
        perror("listen");
        close(socketfd);
        return -1;
    }

    return socketfd;
} //监听状态套接字



