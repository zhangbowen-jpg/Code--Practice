/*************************************************************************
	> File Name: euler03.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月31日 星期三 16时40分06秒
 ************************************************************************/

#include<stdio.h>
#define N 600851475143LL

//在数字后面打一个LL，表示宏定义一个long long类型的数
int main() {
    long long i = 2, ans = 0, num = N;
    while(i * i <= num) {
        if(num % i == 0) ans = i; //这里的值是素数
        while(num % i == 0) {
        num /= i;
        i += 1;
        }
    }
    if(num != 1) ans = num;
    printf("%lld/n",ans)
    return 0;
}

