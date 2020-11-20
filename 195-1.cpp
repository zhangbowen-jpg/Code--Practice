/*************************************************************************
	> File Name: 195-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月21日 星期三 15时48分33秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define max_n 10000

int arr[max_n + 5] = {0};

int binary_search(int *arr, int l, int r, int x) {
    int head = l, tail = r - 1, mid;
    while(head < tail) {
        mid = ceil((head + tail) >> 1);
        if(arr[mid] <= x) head = mid;
        else tail = mid - 1;
    }
    return head;
}

void solve(int n,int m) {
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 1; i <= m; i++){
    int x;
    cin >> x;
    if(i == 1) cout << binary_search(arr,0,n,x);
    else cout << " " << binary_search(arr,0,n,x);
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    solve(n,m);
    return 0;
}
