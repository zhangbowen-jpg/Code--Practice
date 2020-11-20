/*************************************************************************
	> File Name: 109.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月21日 星期日 18时14分11秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int a;
    scanf("%d",&a);
    if((a/1000)%2==0||((a%1000)/100)%2==0||((a%100)/10)%2==0||(a%10)%2==0){
    printf("YES");
    }
    else{
    printf("NO");
    }
    return 0;
}

