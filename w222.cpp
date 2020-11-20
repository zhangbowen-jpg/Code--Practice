/*************************************************************************
	> File Name: w222.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月11日 星期四 18时41分26秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<cmath>
using namespace std;
#define MAX_N 10000
int arr[MAX_N+5]

struct Node{
    int l,r,num;
}tree[MAX_N<<2+5];
//线段树存储空间
//ind 当前结点编号
void Up(int ind){
    tree[ind].num=max(tree[ind<<1].num,tree[ind<<1|1].num);
}


void build(int *arr,int ind,int l, int r,){
    tree[ind].l = l;
    tree[ind].r = r;
    if(l==r){
        tree[ind].num = arr[l];
        return ;
    }
    //ind*2 代表左子树 ind*2+1代表右子树
    int mid = (l+r)>>1;
    build(arr,ind*2,l,mid);
    build(arr,ind*2+1,mid+1,r);
    Up(ind);
    return ;
}

void modify(int ind,int i,int x){
    if(tree[ind].l==tree[ind].r){
        tree[ind].num = x;
        return ;
    }
    int mid = (tree[ind].l+tree[ind].r)>>1;
    if(i<=mid)modify(ind << 1,i,x);
    else modify(ind<<1|1,i,x);
    Up(ind);
    return ;
}
//query 找区间最大值
int query(int ind,int l,int r){
    if(l<=tree[ind].l&&tree[ind].r<=r){
        return tree[ind].num;
    }
    int mid = (tree[ind].l+tree[ind].r)>>1;
    int ans = 0x80000000;
    if(l<=mid){
        ans = max(ans,query(ind<<1,l,r));
    }
    if(r>=mid){
        ans = max(ans,query(ind<<1|1,l,r));
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        build(arr,1,0,n-1);
        
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        switch(a){
            case 1:modify(1,b,c);break;
            case 2:cout<<query(1,b,c)<<endl;break;
            }
    }
    }
}
