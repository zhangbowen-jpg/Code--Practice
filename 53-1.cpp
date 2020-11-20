/*************************************************************************
	> File Name: 53-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月23日 星期五 16时38分38秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define max_n 1000000

int sum(int n) {
    int num = 1;
    for(int i = 2; i <= n / 2; i++) {
        if(n % i == 0) num += i;
    }
    return num;
}

int main() {
    int t,ans = 0;
    for (int i = 2; i < max_n; i++) {
        t = sum(i);
        if(ans < t) ans = t;
    }
    printf("%d",ans);
    return 0;
}

