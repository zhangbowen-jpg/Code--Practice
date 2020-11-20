/*************************************************************************
	> File Name: 190.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月10日 星期六 15时28分56秒
 ************************************************************************/

#include<iostream>
using namespace std;

int num[8000005] = {1,1};

int main() {
    int n;
    cin >> n;
    for (int i = 2; i * i <= n; i++) {
        if (!num[i]) {
            for (int j = 2; i * j <= n; j++) {
                num[i * j] = 1;
            } 
        }
    }
    int ans = 0;
    for (int i = 2; i * 2 <= n; i++) {
        if (!num[i] && !num[n - i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

