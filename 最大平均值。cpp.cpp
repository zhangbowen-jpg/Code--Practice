#include<vector>
#include<map>
#include<math>
using namespace std;
#define MAX_N 1000
int arr[MAX_N+5];
bool check(int *arr,int n,int m)
{
	int sj = 0, min_num,si = 0;
	for(int i = 0;i<m;i++)
	{
	  sj += arr[i];	
	}
	if (sj>=0) return true;
	for(int i = 0;i<=n;i++)
	{
	sj += arr[i]
	si += arr[i-m];
	min_num = min(si,min_num);
	if (min_num<=sj) return true;	
	}
	return false;
}
int binary_search(int *arr,int n,int m,int l,int r){
	if (l==r) return l;
	int mid = (l+r+1)>>1
	if (check(arr,n,m,mid)) return binary_search(arr,n,m,mid,r); 
   else return binary_search(arr,n,m,l,mid-1);
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n,i++)
	{
		cin>>arr[i]
		if (i==0) num_min=arr[i],num_max=arr[i];
		num_min=min(arr[i],num_min);
		num_max = max(arr[i],num_max);
	}
		cout<<check(arr,n,m)<<endl;
	return 0;	
}
   	
 
