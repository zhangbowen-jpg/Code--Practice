#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <string.h> 
#define MAX_N 1000
using namespace std;
int arr[MAX_N+5];
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
		int a,b;
		cin>>a>>b;
		arr[a]+=1;arr[b+1]-=1;
		output(t);
	}
	return 0;
}
