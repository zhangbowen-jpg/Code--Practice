/*************************************************************************
	> File Name: 142-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月05日 星期一 20时04分47秒
 ************************************************************************/

#include<stdio.h>

int isvaild(int n) {
    for(int i=2; i < n; i++) {
        if (n%i==0) return false;
        else continue;
    }
    return true;
}

int ishuiwen(int x) {
    int temp = x, sum = 0;
    while(x) {
        sum = sum * 10 + x % 10;
        x /= 10;
    }
    return temp == sum;
}

int main() {
    int a, b, n = 0;
    scanf("%d%d", &a, &b);
    for (int i = a; i <= b; i++) {
    if (ishuiwen(i)){
        if (isvaild(i)) {
            if (n==1){
                printf(" ");
            }
        printf("%d", i);
        n = 1;
        }
    }
    }
    return 0;
}

