/*************************************************************************
	> File Name: 130.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月23日 星期二 19时31分45秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int m,n;
    double sum=0;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++){
        sum=(m+sum)*(1.00417); 
    }
    printf("$%.2f",sum);
    return 0;
}

