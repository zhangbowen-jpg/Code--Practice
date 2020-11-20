/*************************************************************************
	> File Name: 180.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月02日 星期五 14时00分22秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int num,i,j,temp,digit=1;
    scanf("%d",&num);
int p[40000]={0};
     p[0]=1;
     digit=1; 
    for(i=1;i<=num;i++)
 {
       int c=0;
    for(j=1;j<=digit;j++)
   {
	temp=p[j-1]*2+c;
	p[j-1]=temp%10;
	c=temp/10;
 } 
 while(c!=0)
 {
   p[++digit-1]=c%10;
            c=c/10;
	}
			}
			for(j=digit-1;j>=0;j--)
			printf("%d",p[j]);	
		return 0;
}

