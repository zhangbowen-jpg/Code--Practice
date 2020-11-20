/*************************************************************************
	> File Name: 140.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 23时43分51秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1;i <= n; i++) {
        for(int j = 1;j < n+i; j++) {
            if(j >= (n-i+1)){
                printf("%c",'A'+(i-1));
            }
            else printf(" ");
        }
        printf("\n");
    }
    for(int i = n-1; i >= 1; i--) {
        for(int j = 1;j < n+i; j++) {
            if(j >= (n-i+1)){
                printf("%c",'A'+(i-1));
            }
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}

