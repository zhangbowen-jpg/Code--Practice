/*************************************************************************
	> File Name: 137.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 14时24分31秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<(n*n+n)/2;i++){
    printf("%c",'A'+i);
    if(i==n-1){
    printf("\n");
    }
    else if(i==2*n-2){
    printf("\n");
    }
    else if(i==3*n-4){
    printf("\n");
    }
    else if(i==4*n-7){
    printf("\n");
    }
    else if(i==5*n-11){
    printf("\n");
    }
    else if(i==6*n-16){
    printf("\n");
    }
    else continue;
    }
    return 0;
}

