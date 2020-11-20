/*************************************************************************
	> File Name: 186.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月08日 星期四 11时39分16秒
 ************************************************************************/

#include<stdio.h>

int tan(int x,int arr[]) {
    int sum = 1,num = 0;
    while(sum <= x) {
        sum += arr[sum - 1];
        num++;
    }
    return num;
}

int main() {
    int n,s;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    s = tan(n,arr);
    printf("%d",s);
}

