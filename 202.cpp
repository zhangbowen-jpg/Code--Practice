/*************************************************************************
	> File Name: 202.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月14日 星期三 13时39分44秒
 ************************************************************************/

#include<stdio.h>
#define max_n 1000

int arr[max_n + 5];
int ans[max_n + 5];

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int n,flag = 0,temp1,temp2;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) {
        scanf("%d",&arr[i]);
        ans[i] = i;
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= n - i; j++) {
            if(arr[j] > arr[j + 1]) {
            swap(arr[j],arr[j + 1]);
            swap(ans[j],ans[j + 1]);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(flag == 1) printf(" ");
        printf("%d",ans[i]);
        flag = 1;
    }
    return 0;
}


