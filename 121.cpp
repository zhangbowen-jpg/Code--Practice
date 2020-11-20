/*************************************************************************
	> File Name: 121.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月21日 星期日 20时17分37秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    char n,m;
    scanf("%c %c",&n,&m);
    if(n=='O'){
     if(m=='Y')printf("MING");
     else if(m=='O')printf("TIE");
     else printf("LI");
    }
    else if(n=='Y'){
     if(m=='O')printf("LI");
     else if(m=='Y')printf("TIE");
     else printf("MING");
    }
    else{
     if(m=='O')printf("MING");
     else if(m=='Y')printf("LI");
     else printf("TIE");
    }
    return 0;

}

