/*************************************************************************
	> File Name: 157.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月27日 星期六 19时00分17秒
 ************************************************************************/


#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) {
            if(j>=i){
                printf("%c",'A'+j-1);
            } else printf(" ");
        }
        for(int j = n-1; j >= i; j--) {
            printf("%c",'A'+j-1);
        }
    printf("\n");
    }
    for(int i = n-1; i >= 1; i--){
        for(int j = 1; j <= n; j++) {
            if(j>=i){
                printf("%c",'A'+j-1);
            } else printf(" ");
        }
        for(int j = n-1; j >= i; j--) {
            printf("%c",'A'+j-1);
        }
    printf("\n");
    }
    return 0;
}

