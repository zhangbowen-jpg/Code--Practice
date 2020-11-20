#include<stdio.h>
#include<inttypes.h> 
#define NUM 60000000000 
int main()
{
    int64_t num=NUM,n=2,ans=0;
    while(n*n<=NUM)
    {
    	if(num%n==0)ans=n;
    	while(num%n==0)num/=n;
		n+=1; 
	}
	if(num!=1)ans=num;
	printf("%PRId64/n",ans);
	return 0;
}
