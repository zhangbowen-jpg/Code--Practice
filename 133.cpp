/*************************************************************************
	> File Name: 133.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 13时51分06秒
 ************************************************************************/
#include<stdio.h>
int main(){
    int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++){
		for(int j=i;j<a;j++){
		printf("%d*%d=%d\t",i,j,i*j);
		}
	printf("%d*%d=%d",i,a,i*a);
	printf("\n");
	}
    return 0;
}
