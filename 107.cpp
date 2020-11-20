/*************************************************************************
	> File Name: 107.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月21日 星期日 18时04分23秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    if(n%7!=0){
    printf("NO");
    }
    else if((n/7)%2==0){
    printf("NO");
    }
    else{
    printf("YES");}
    return 0;
}

