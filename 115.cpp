/*************************************************************************
	> File Name: 115.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月21日 星期日 18时38分01秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,e,f;
    scanf("%d%d",&a,&b);
    d = b%10;
    c = b/10;
    e = a/10;
    f = a%10;
    if(a==d*10+c){
    printf("20");
    }
    else if(a==b){
    printf("100");
    }
    else if((d==e)||(d==f)||(c==e)||(c==f)){
    printf("2");
    }
    else{
    printf("0");
    }
}

