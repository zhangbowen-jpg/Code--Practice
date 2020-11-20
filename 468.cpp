/*************************************************************************
	> File Name: 468.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月19日 星期一 20时12分53秒
 ************************************************************************/

#include<stdio.h>

int gcd(int a,int b) {
    return (b ? gcd(b,a % b) : a);
}

int main() {
    int m,n,ans;
    scanf("%d%d",&m,&n);
    ans = gcd(m,n);
    printf("%d",ans);
    return 0;
}

