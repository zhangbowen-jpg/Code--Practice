#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <string.h> 
#define MAX_N 1000
using namespace std;
int c[MAX_N+5];
int arr[MAX_N+5];
inline int lowbit(int x){ return x&-x; }
int query(int x){
	int sum=0;
	while(x) sum+=c[x],x-=lowbit(x);
	return sum; 
}
void add(int x,int val,int n){
	while(x<=n) c[x]+=val,x+=lowbit(x);
}
void output(int t)
{
	for(int i=1;i<=t;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
} 
int main()
{
	int t,n;
	cin>>t>>n;
	for(int i=0;i<n;i++){
		int c,a,b;
		cin>>c;
		switch(c){
			case 0:{
			cin>>a>>b;
			add(a,1,t);
			add(b+1,-1,t);	
			}break;
			case 1:{
				cin>>a;
				int ans=0;
				for(int i=1;i<=a;i++){
					ans+=arr[i];
				}
				cout<<"People:"<<query(a)<<endl;
			}break;
		}
		arr[a]+=1;arr[b+1]-=1;
		output(t);
	}
	return 0;
}
