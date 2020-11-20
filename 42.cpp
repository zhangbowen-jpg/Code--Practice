/*************************************************************************
	> File Name: 42.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月09日 星期二 15时55分10秒
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
#define MAX_N 10000
#define MAX_M 20
int w[MAX_M + 5];
int f[MAX_N + 5];

int main() {
    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) cin >> w[i];
    f[0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = w[i]; j <= n; j++) {
            f[j] += f[j - w[i]];
            f[j] %= 9973;
        }
    }
    cout << f[n] << endl;
    return 0;
}

