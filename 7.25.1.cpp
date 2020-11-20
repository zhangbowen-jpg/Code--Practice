/*************************************************************************
	> File Name: 7.25.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 15时41分50秒
 ************************************************************************/
#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("FOOLISH\n");
    } else if (n < 60) {
        printf("FAIL\n");
    } else if (n < 75) {
        printf("MEDIUM\n");
    } else printf("GOOD\n");
    return 0;
}

