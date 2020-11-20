/*************************************************************************
	> File Name: 268.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月09日 星期二 10时42分15秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
//使用二维队列(链表也行)
#define MAX_N 1000
#define MAX_X 1000000
queue<int>  q[MAX_N+5];
queue<int>  main_q;
int ind[MAX_X+5];

int main(){
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        for(int j=0;j<m;j++){
            int a;
            cin>>a;
            ind[a] =i;
        }
    }
    string op;
    while(cin>>op){
        if(op=="STOP"){
            break;
        }else if(op=="ENQUEUE"){
            int a;
            cin>>a;
            q[ind[a]].push(a);
            if(q[ind[a]].size()==1)main_q.push(ind[a]);
        }else{
            int k = main_q.front();
            cout<<q[k].front()<<endl;
            q[k].pop();
            if (q[k].size()==0) main_q.pop();
        }

    }
    return 0;
}
