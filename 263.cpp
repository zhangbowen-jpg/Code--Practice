/*************************************************************************
	> File Name: 263.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月09日 星期二 09时57分31秒
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
void output(int*arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    cout<<endl;
    return ;
}
int valid(int *arr,int n){
    stack<int> s;//创建栈
    int num=0;//入栈的元素
    for(int i=0;i<n;i++){
        while(num<arr[i]){
            num++;
            s.push(num);
        }
        if(s.top()!=arr[i]) return false;
        s.pop();
    }
    return true;
}



int main(){
   int n,cnt =20;
    cin>>n;
    for(int i=0;i<n;i++) arr[i]=i+1;
    do {
        if(valid(arr,n)){
            output(arr,n);
            cnt -= 1;
        } 
    } while(next_permutation(arr,arr+n)&&cnt);//求下一个序列的状态 prev_permutation前一个序列
    return 0;
}
