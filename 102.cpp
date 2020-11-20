/*************************************************************************
	> File Name: 102.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月21日 星期日 16时56分59秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    double a,b,c,t;
    double z;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&t);
    printf("%.2f",(a*b*c-a*b*t)/(b*c+a*c-a*b));
}

