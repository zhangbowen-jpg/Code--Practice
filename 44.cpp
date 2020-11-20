/*************************************************************************
	> File Name: 44.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月16日 星期五 20时11分24秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
#define max_n 1000000

int arr[max_n + 5];
int ans[max_n + 5];
int lon = 0;

int binary_search(int x) {
    int head = 1, tail = lon;
    while(head < tail) {
        int mid = (head + tail) >> 1;
        if(ans[mid] >= x) {
            tail = mid;
        } else head = mid + 1;
    }
    return head;
}

int main() {
    int m,sum;
    scanf("%d",&m);
    for(int i = 1; i <= m; i++) {
        scanf("%d", &arr[i]);
    }
    ans[++lon] = arr[1]; 
    for(int i = 2; i <= m; i++) {
        if(arr[i] > ans[lon]) ans[++lon] = arr[i];
        else{
            sum = binary_search(arr[i]);
            ans[sum] = arr[i];
        }
    }
    printf("%d",lon);
    return 0;
}



