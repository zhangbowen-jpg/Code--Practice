/*************************************************************************
	> File Name: 116.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月21日 星期日 18时46分55秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if((a+b<c)||(a+c<b)||(b+c<a)){
    printf("illegal triangle");
    }
    else{
    if(a<c&&b<c){
        if((a*a+b*b)<c*c){
        printf("obtuse triangle");
        }
        else if((a*a+b*b)==c*c){
        printf("right triangle");
        }
        else{
        printf("acute triangle");
        }
    }
    else if(a<b&&c<b){
    if((a*a+c*c)<b*b){
        printf("obtuse triangle");
        }
        else if((a*a+c*c)==b*b){
        printf("right triangle");
        }
        else{
        printf("acute triangle");
        }
    }
    else{
    if((c*c+b*b)<a*a){
        printf("obtuse triangle");
        }
        else if((c*c+b*b)==a*a){
        printf("right triangle");
        }
        else{
        printf("acute triangle");
        }
    }
    }
}

