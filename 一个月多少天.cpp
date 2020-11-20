/*************************************************************************
	> File Name: 一个月多少天.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月12日 星期五 17时53分07秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<stdio.h>
using namespace std;
int main()                              
{   int y,x;                             
    cin >> y >> x;
    switch(x){
        case 12:           
        case 10: 
        case 8:
        case 7:
        case 5:
        case 3:
        case 1:cout<<31<<endl;break;
        case 2: if((y%4==0&&y%100!=0)||
                      (y%400==0)) cout<<29<<endl;
                   else cout<<28<<endl;break;
        case 6:
        case 4:
        case 9:
        case 11:
        cout<<30<<endl;break;
    }              
 return 0;                              
}
 
