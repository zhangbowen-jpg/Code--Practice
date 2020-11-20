/*************************************************************************
	> File Name: 237.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月07日 星期日 18时20分13秒
 ************************************************************************/

#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
#define MAX_N 8
int arr[MAX_N+5];
void swap(int &a,int &b){
    int temp =a;
    a=b;
    b=temp;
}
void func(int k,int n,int arr[]){
    if(k==n){
        for(int i=0;i<n;i++)
        {
            i == 0||cout<<" ";
            cout<<arr[i];
        }
        cout<<endl;
        return ;
    }
    for(int i=k;i<n;i++)
    {
        swap(arr[k],arr[i]);
        func(k+1,n,arr);
        swap(arr[i],arr[k]);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    func(0,n,arr);
}

