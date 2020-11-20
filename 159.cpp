/*************************************************************************
	> File Name: 159.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月29日 星期一 18时25分57秒
 ************************************************************************/

#include<stdio.h>

int main() {
    char str;
    int n;
    scanf("%c", &str);
    n = str-'A';
    for(int i = 1; i <= n+1; i++) {
        for(int j = 1; j <= 2*(n+1) - i; j++) {
            if((j >= i) &&(j <= (n+1))) {
                printf("%c",'A'+n-j+1);
            } else if(j > (n+1)) {
                printf("%c",'A'+j-n-2);
            } else {
                printf(" ");
            }  
        }
        printf("\n");
    }
    return 0;
}

