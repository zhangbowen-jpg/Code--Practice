/*************************************************************************
	> File Name: 195.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月14日 星期三 13时51分52秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int num[100005] = {0};

int binary_search(int x, int n) {
    int head = 0, tail = n - 1, mid;
    while(head < tail) {
        mid = (head + tail + 1) / 2;
        if(num[mid] <= x) head = mid;
        else tail = mid - 1;
    }
    return num[head];
}

/*
 *int binary_search2(int x, int n) {
    int head = 0, tail = n - 1, mid;
    while(head < tail){
    mid = (head + tail) >> 1;
    if(arr[mid] >= x) tail = mid;
    else head = mid + 1;
    }
 }
 *
 */
int main() {
    int n,m,score,flag = 0;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++) {
        scanf("%d",&num[i]);
    }    
    for(int i = 1; i <= m; i++) {
        scanf("%d",&score);
        if(flag == 1) {
            printf(" ");
        }
        printf("%d",binary_search(score, n));
        flag = 1;
    }
    return 0;
}

