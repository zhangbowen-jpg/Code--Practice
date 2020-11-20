/*************************************************************************
	> File Name: 90.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月21日 星期日 16时11分05秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int a;
    scanf("%d",&a);
    printf("%d\n",a/100);
    printf("%d\n",(a%100)/10);
    printf("%d",(a%100)%10);
    return 0;
}

