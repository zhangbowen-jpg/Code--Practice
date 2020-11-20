/*************************************************************************
	> File Name: 132.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月23日 星期二 20时44分47秒
 ************************************************************************/

#include<stdio.h>
int main(){
    int n,m;
    long long num=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&m);
        num*=m;
    }
    printf("%lld",num);
}

