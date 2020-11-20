/*************************************************************************
	> File Name: 7.25.3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 16时02分10秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    switch (n) {
        case 1: printf("one ");
        case 2: printf("two ");
        case 3: printf("three\n"); break;
        default: printf("error\n"); break;
    }
    return 0;
}

