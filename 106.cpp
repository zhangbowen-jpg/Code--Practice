/*************************************************************************
	> File Name: 106.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月21日 星期日 17时55分03秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    double n;
    scanf("%lf",&n);
    if(n<0){
     n = 0-n;
    }
    else{
    n = 0+n;
    }
    printf("%g",n);
}

