/*************************************************************************
	> File Name: 丰收.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月14日 星期五 13时59分21秒
 ************************************************************************/
#include <iostream>
using namespace std;

int a[100005] = {0};

int bs(int l, int r, int t) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (a[mid] >= t) return bs(l, mid, t);
    return bs(mid + 1, r, t);
}

int main() {
    int n, m, t;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> t;
        cout << bs(1, n, t) << endl;
    }
    return 0;
}
