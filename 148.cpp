/*************************************************************************
	> File Name: 148.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月29日 星期一 18时59分43秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int i = 0,sum = 0;
    char str[50];
    scanf("%c",&str[i]);
    while(str[i]!='\n') {
        i++;
        scanf("%c",&str[i]);
        sum++;
    }
    for(int i = sum-1; i >= 0; i--){
        printf("%c",str[i]);
    }
    return 0;
}

