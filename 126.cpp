/*************************************************************************
	> File Name: 126.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月23日 星期二 15时52分29秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
#define PI 3.14
using namespace std;
int main(){
    double a,b;
    scanf("%lf%lf",&a,&b);
    printf("%.2f",PI*(a*a-b*b));
    return 0;
}

