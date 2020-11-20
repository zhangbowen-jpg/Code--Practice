/*************************************************************************
	> File Name: 571.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月03日 星期日 23时54分39秒
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>
using namespace std;
#define MAX_N 100
int arr[MAX_N + 5][MAX_N + 5];

struct Data {
    Data(int a, int b, int c) {
        x = a, y = b, cnt = c;
    }
    int cnt, x, y;
};

struct DataCompare {
    bool operator()(const Data &a, const Data &b) const {
        if (a.cnt - b.cnt) return a.cnt < b.cnt;
        if (a.x - b.x) return a.x < b.x;
        return a.y < b.y;
    }
};

set<Data, DataCompare> s;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            if (arr[i][j]) {
                s.insert(Data(i, j, 1));
            }
        }
    }
    while (s.size()) {
        int x = s.begin()->x;
        int y = s.begin()->y;
        int cnt = s.begin()->cnt;
        s.erase(s.begin());
        for (int i = 1; i <= n; i++) {
            if (arr[y][i] != 1) continue;
            if (arr[x][i]) continue;
            arr[x][i] = cnt + 1;
            s.insert(Data(x, i, cnt + 1));
        }
    }
    cout << arr[x][y] - 1 << endl;
    return 0;
}
