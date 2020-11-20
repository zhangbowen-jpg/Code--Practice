/*************************************************************************
	> File Name: 100.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月21日 星期日 16时47分14秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
#define LI 0.00417
using namespace std;
int main(){
    double a;
    scanf("%lf",&a);
    double sum = 0;
    for(int i=1;i<=6;i++){
    sum = (sum+a)*(1+LI);
    }
    printf("$%.2f",sum);
}

