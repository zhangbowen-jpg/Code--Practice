/*************************************************************************
	> File Name: 129.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 13时49分46秒
 ************************************************************************/
#include<stdio.h>
int main(){
    int n,m;
    int num=10001;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&m);
		if(num>=m){num=m;}
	}
    printf("%d",num);
}

