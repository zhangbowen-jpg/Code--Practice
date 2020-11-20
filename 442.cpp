/*************************************************************************
	> File Name: 442.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月14日 星期三 19时52分12秒
 ************************************************************************/

#include<stdio.h>

int digui(int n) {
    if(n == 1) return 1;
    if(n == 2) return 2;
    return digui(n-1) + digui(n-2);
}

int main() {
    int n,ans,flag = 0;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) {
        if(flag == 1) printf(" ");
        ans = digui(i);
        printf("%d",ans);
        flag = 1;
    }
    return 0;
}

