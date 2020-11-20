#include<stdio.h> 
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main(){
	long long a,n,p;
	cin>>a>>n>>p;
	long long temp = a,ans =1; 
	while(n){
		if(n%2) ans=ans*temp%p;
		temp = temp*temp%p;
		n/=2;
	}
	cout<<ans%p<<endl;
	return 0;
} 
// 求a的b次方对p取模的值。

