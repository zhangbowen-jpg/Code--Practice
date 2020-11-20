/*************************************************************************
	> File Name: 465.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月12日 星期一 20时42分12秒
 ************************************************************************/

#include<stdio.h>

int digits(long long x,int k) {
    int n;                           
    for(int i = 1; i <= k; i++) {
        n = x % 10;
        x /= 10;
    }    
    return n;
}


int main() {
    long long n;
    int k,p;
    scanf("%lld%d",&n,&k);
    p = digits(n,k);
    printf("%d",p);
    return 0;
}

