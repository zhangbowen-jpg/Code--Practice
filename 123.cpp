/*************************************************************************
	> File Name: 123.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月23日 星期二 14时30分17秒
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int a,b,c,d; 
    scanf("%d%d",&a,&b);
    scanf("%d%d",&c,&d);
    if((a<=c&&b>=d)||(a>=c&&b<=d)){
    printf("YES");
    }
    else printf("NO");
}


