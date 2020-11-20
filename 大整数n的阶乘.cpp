/*************************************************************************
	> File Name: 大整数n的阶乘.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月09日 星期五 20时04分36秒
 ************************************************************************/

#include<stdio.h>

int p[50000] = {0};

int main() {
    int num,temp,digit = 1;
    scanf("%d", &num);
    p[0] = 1;
    digit = 1;
    for(int i = 1; i <= num; i++) {
        int c = 0;
        for(int j = 1; j <= digit; j++) {
            temp = p[j - 1] * i + c;
            p[j - 1] = temp % 10;
            c = temp / 10;
        }
    while(c != 0) {
        p[++digit - 1] = c % 10;
        c = c / 10;
    }
    }
    for(int j = digit - 1; j >= 0; j--) printf("%d",p[j]);
    return 0;
}

