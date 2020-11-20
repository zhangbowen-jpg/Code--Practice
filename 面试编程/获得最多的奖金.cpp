/*************************************************************************
	> File Name: 获得最多的奖金.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月14日 星期五 14时01分56秒
 ************************************************************************/
#include <iostream>
using namespace std;

long long a[200005];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long p1 = 0, p2 = n + 1, s1 = 0, s2 = 0, ans = 0;
    while (p1 + 1 < p2) {
        if (s1 > s2) {
            s2 += a[--p2];
        } else {
            s1 += a[++p1];
        }
        if (s1 == s2) ans = max(ans, s1);
    }
    cout << ans << endl;
    return 0;
}
