/*************************************************************************
	> File Name: 175.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月01日 星期四 01时32分41秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int n,Y=0,L=0,Z=0,C=0,num;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) {
        scanf("%d",&num);
        if(num >= 90) Y++;
        else if(num >= 80) L++;
        else if(num >= 60) Z++;
        else C++;
    }
    printf("You %d\n",Y);
    printf("Liang %d\n",L);
    printf("Zhong %d\n",Z);
    printf("Cha %d",C);
    return 0;
}

