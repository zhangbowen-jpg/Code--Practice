/*************************************************************************
	> File Name: 117.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月21日 星期日 19时00分38秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int a,k,n=0;
    scanf("%d",&a);
    k = a;
    while(k>0){
    n=n*10+k%10;
    k=k/10;
    }
    if(n==a) printf("YES");
    else printf("NO");
    return 0;
}

