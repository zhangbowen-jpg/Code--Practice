/*************************************************************************
	> File Name: 108.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月21日 星期日 18时08分12秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    char z;
    double m,n;
    scanf("%c",&z);
    scanf("%lf%lf",&m,&n);
    if(z=='r'){
    printf("%.2f",m*n);
    }
    else{
    printf("%.2f",(m*n)/2);
    }
    return 0;
}

