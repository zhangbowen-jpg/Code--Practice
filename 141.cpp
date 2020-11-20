/*************************************************************************
	> File Name: 141.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 23时56分22秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n+1; i++){
        for(int j = 1; j <= n+1; j++) {
            if(j>=i){
                printf("%c",'A'+j-1);
            } else printf(" ");
        }
        for(int j = n; j >= i; j--) {
            printf("%c",'A'+j-1);
        }
    printf("\n");
    }
    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= n+1; j++) {
            if(j>=i){
                printf("%c",'A'+j-1);
            } else printf(" ");
        }
        for(int j = n; j >= i; j--) {
            printf("%c",'A'+j-1);
        }
    printf("\n");
    }
    return 0;
}

