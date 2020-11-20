/*************************************************************************
	> File Name: 火车进栈.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月12日 星期五 19时15分27秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<cstring>
#include<cstdlib>
#include<stack>
using namespace std;
#define MAX_N 20
int arr[MAX_N+5];
void qvyuansu(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    cout<<endl;
    return ;
}
int zhancaozuo(int *arr,int x){
    stack<int> stacks;
    int num=0;
    for(int i=0;i<x;i++){
        while(num<arr[i]){
            num++;
            stacks.push(num);
        }
        if(stacks.top()!=arr[i]) return false;
        stacks.pop();
    }
    return true;
}



int main(){
   int n,y=20;
    cin>>n;
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    do {
        if(zhancaozuo(arr,n)){
            qvyuansu(arr,n);
            y -= 1;
        } 
    } while(next_permutation(arr,arr+n)&&y);
    return 0;
}

