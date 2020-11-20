/*************************************************************************
	> File Name: 467.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月12日 星期一 20时20分37秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    unsigned long long sum = 1;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) {
        sum *= i;
    }
    printf("%lld",sum);
    return 0;
}

