/*************************************************************************
	> File Name: 101.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月21日 星期日 16时52分39秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",n/10000+(n%10000)/1000+(n%1000)/100+(n%100)/10+n%10);
    return 0;
}

