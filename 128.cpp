/*************************************************************************
	> File Name: 128.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月21日 星期日 20时35分16秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
#define MAX_N 10000
int arr[MAX_N+5];
using namespace std;
int main(){
    double n,m,num=0;
    scanf("%lf",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf",&m);
        num+=m;
    }
    printf("%.2f",num/n);
    return 0;
}

