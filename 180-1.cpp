/*************************************************************************
	> File Name: 180-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月07日 星期三 20时46分37秒
 ************************************************************************/

#include<stdio.h>

int p[40000] = {0};

int main() {
    int num;
    scanf("%d",&num);
    p[1] = 1;
    p[0] = 1;
    for(int j = 1; j <= num; j++) {
        for(int i = 1; i <= p[0]; i++) {
        p[i] *= 2;
        }
        for(int i = 1; i <= p[0]; i++ ){
        if(p[i] < 10) continue;
        p[i + 1] += p[i] / 10;
        p[i] %= 10;
        p[0] += (i == p[0]);
        }
    }
    for(int i = p[0]; i >= 1; i--){
        printf("%d",p[i]);
    }
    return 0;
}

