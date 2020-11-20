/*************************************************************************
	> File Name: 235.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月07日 星期日 11时11分48秒
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
#define MAX_N 10
int arr[MAX_N + 5];

void meijv(int k, int ind, int n, int *arr) {
    if (k != 0) {
        for (int i = 0; i < k; i++) {
            i == 0 || cout << " ";
            cout << arr[i];
        }
        cout << endl;
    }
    for (int i = ind; i <= n; i++) {
        arr[k] = i;
        meijv(k + 1, i + 1, n, arr);
    }
    return ;
}

int main() {
    int n;
    cin >> n;
    meijv(0, 1, n, arr);
    return 0;
}

