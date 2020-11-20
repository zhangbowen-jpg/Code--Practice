/*************************************************************************
	> File Name: 尔罗斯方块.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月14日 星期五 13时58分08秒
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
#define MAX_N 1000

int main() {
    int n, m, a, b,Min = MAX_N + 5;
    cin >> n >> m;
    int arr[n];
    memset(arr, 0, sizeof(int)*n);
    for(int i = 0; i < m; i++) {
        cin >> a;
        b = arr[a - 1];
        b++;
        arr[a - 1] = b;
    }
    for(int i = 0; i < n; i++) {
        Min = min(Min, arr[i]);
    }
    cout << Min << endl;
    return 0;
}

