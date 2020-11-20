/*************************************************************************
	> File Name: 104.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月21日 星期日 17时11分12秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int a;
    scanf("%d",&a);
    if(a/100!=9&&(a%100)/10!=9&&a%10!=9){
    printf("NO");
    }
    else{
    printf("YES");
    }
}

