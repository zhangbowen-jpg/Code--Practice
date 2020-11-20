/*************************************************************************
	> File Name: 127.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月23日 星期二 16时05分44秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    double a;
    int m,b;
    scanf("%lf%d",&a,&b);
    for(int i=1;i<=b;i++){
        a=a*(1.06);
    }
    m=(int)(a);
    printf("%d",m);
    return 0;
}

