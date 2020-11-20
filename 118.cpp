/*************************************************************************
	> File Name: 118.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月21日 星期日 19时07分00秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int year,x;
    scanf("%d",&year);
    x = year%12;
    switch(x){
        case 0: printf("monkey");break;
        case 1: printf("rooster");break;
        case 2: printf("dog");break;
        case 3: printf("pig");break;
        case 4: printf("rat");break;
        case 5: printf("ox");break;
        case 6: printf("tiger");break;
        case 7: printf("rabbit");break;
        case 8: printf("dragon");break;
        case 9: printf("snake");break;
        case 10: printf("horse");break;
        case 11: printf("sheep");break;
    }
    return 0;
}

