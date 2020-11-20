/*************************************************************************
	> File Name: 110.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月21日 星期日 18时18分49秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    double x;
    scanf("%lf",&x);
    if(x>15){
    printf("%.2f",(x-15)*9+90);
    }
    else{
    printf("%.2f",x*6);
    }
    return 0;
}

