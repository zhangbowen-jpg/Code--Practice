/*************************************************************************
	> File Name: 迷路的牛牛.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月10日 星期一 16时17分03秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;

int main(){
    int n,t=0;
    char c;
    while(cin>>n){
        t=0;
        for(int i=0;i<n;i++){
            cin>>c;
            if(c=='R'){
                t++;
                t%=4;
            }
            else{
                if(t==0){
                    t=3;
                }
                else{
                    t--;
                }
            }
        }
        if(t==0)
        cout<<'N'<<endl;
        else if(t==1)
        cout<<'E'<<endl;
        else if(t==2)
        cout<<'S'<<endl;
        else if(t==3)
        cout<<'W'<<endl;
    }
    return 0;
}

