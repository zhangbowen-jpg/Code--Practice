/*************************************************************************
	> File Name: 466.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月12日 星期一 20时34分09秒
 ************************************************************************/

#include<stdio.h>

int is_vaild(int n) {
    int tmp = n,x = 0;
    while (tmp){
        x = x * 10 + tmp % 10;
        tmp /= 10;
    }
    if(x == n) return 1;
    else return 0;
}

int main() {
    int n,sum = 0;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) {
        if(!is_vaild(i)) continue;
        sum++;
    }
    printf("%d",sum);
}

