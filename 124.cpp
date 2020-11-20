/*************************************************************************
	> File Name: 124.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月23日 星期二 14时42分38秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if((a>=1||b<=50)&&(c<=25||d>=5)){
    printf("ok");
    }
    else printf("pass");
    return 0;
}


