/*************************************************************************
	> File Name: euler21.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月19日 星期一 14时12分23秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define max_n 10000

int sum(int n) {
    int num = 1;
    for(int i = 2; i <= n / 2; i++) {
        if(n % i == 0) num += i;
    }
    return num;
}

int main() {
    int t,num = 0;
    for (int i = 2; i < max_n; i++) {
        t = sum(i);
        if((t != i) && sum(t) == i) num += i;
    }
    printf("%d",num);
    return 0;
}

