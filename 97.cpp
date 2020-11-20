/*************************************************************************
	> File Name: 97.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月21日 星期日 16时38分08秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int n;
    long long sum=0; 
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    printf("%lld",sum);

}

