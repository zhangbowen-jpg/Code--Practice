/*************************************************************************
	> File Name: 182.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月07日 星期三 16时38分04秒
 ************************************************************************/

#include<stdio.h>
#define max_n 1000000

int main() {
    int num[1000000] = {0};
    int n,max = 0;
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d",&num[i]);
        if(max < num[i]) max = num[i];
    }
    printf("%d",max);
    return 0;
}

