/*************************************************************************
	> File Name: 7.29.5.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月29日 星期一 16时33分51秒
 ************************************************************************/
 //函数的声明与定义

#include<stdio.h>

int funcA(int);//这是声明，不写会报错
int funcB(int);

int funcB(int n) {
    printf("funcB ：%d\n", n);
    if(n == 0) return 0;
    funcA(n-1);
    return n;
}

int funcA(int n) { 
    printf("funcA : %d\n", n);
    if (n == 0) return 0;
    funcB(n-1);
    return n;
}

int main() {
    funcA(6);
    funcB(6);
    return 0;
}


