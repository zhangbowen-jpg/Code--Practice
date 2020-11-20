#include<stdio.h>
#define MAX_LOOP 100
#define MAX_FIB_NUM 4000000 
static int fib[MAX_LOOP]={0,1,2};
int main( )
{
int value=2;
int result=2;
int i;
for(i=3;i<MAX_LOOP;i++)
{
	value=fib[i-1]+fib[i-2];
	if(value>=MAX_FIB_NUM)
	break;
	if((value%2==0))
	{
		result+=value;
	}
	fib[i]=value;
}
printf("%d\n",result);
}
//euler 02
