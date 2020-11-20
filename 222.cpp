/*************************************************************************
	> File Name: 222.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月08日 星期一 19时09分28秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
#define MAX_N 10000
int arr[MAX_N+5];
struct Node{
    int l, r;//起始终止点赋给左右结点
    int num;
}tree[(MAX_N<<2)+5];
//向上更新
void Up(int ind){
    tree[ind].num = max(tree[ind<<1].num,tree[ind<<1|1].num);
}


void build(int *arr,int ind,int l,int r){
    tree[ind].l=l;
    tree[ind].r=r;
    if(l==r){
        tree[ind].num=arr[l];
        return ;
    }
    int mid = (l+r)>>1;
    build(arr,ind*2,l,mid);
    build(arr,ind*2+1,mid+1,r);
    Up(ind);
}
//单点修改
void modify(int ind,int i,int x)
{
    if(tree[ind].l == tree[ind].r){
        tree[ind].num = x;
        return ;
    }
    int mid=(tree[ind].l+tree[ind].r)>>1;
    if(i<=mid) modify(ind<<1,i,x);
    else modify(ind<<1|1,i,x);
    Up(ind);
    return ;
}
//区间查询
int query(int ind,int l,int r){
    if(l<=tree[ind].l&&tree[ind].r<=r){
        return tree[ind].num;
    }
    int mid =(tree[ind].l+tree[ind].r)>>1;
    int ans = 0x80000000;//复数极小值
    if(l<=mid){
        ans = max(ans,query(ind<<1,l,r));
    }
    if(r>mid){
        ans = max(ans,query(ind<<1|1,l,r));
    }
    return ans;
}


int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>arr[i];
    build(arr,1,1,n);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        switch(a){
            case 1:modify(1,b,c);break;
            case 2:cout<<query(1,b,c)<<endl;break;
        }
    }
    return 0;        int a,b,c;
        cin>>a>>b>>c;
        switch(a){
            case 1:modify(1,b,c);break;
            case 2:cout<<query(1,b,c)<<endl;break;
        }
    }
    return 0;

}
