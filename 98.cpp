/*************************************************************************
	> File Name: 98.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月21日 星期日 16时41分40秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
#define PI 3.14
using namespace std;
int main(){
    double r,h;
    scanf("%lf%lf",&r,&h);
    printf("%.2f\n",r*r*PI);
    printf("%.2f",r*r*PI*h);
    return 0;
}

