/*************************************************************************
	> File Name: 236.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月07日 星期日 11时28分13秒
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

void func(int k, int m, int ind, int n, int *arr) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            i == 0 || cout << " ";
            cout << arr[i];
        }
        cout << endl;
        return ;
    }
    for (int i = ind; i <= n; i++) {
        arr[k] = i;
        func(k + 1, m, i + 1, n, arr);
    }
    return ;
}

int main() {
    int n, m;
    cin >> n >> m;
    func(0, m, 1, n, arr);
    return 0;
}

