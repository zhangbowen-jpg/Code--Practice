/*************************************************************************
	> File Name: 193.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月13日 星期二 20时05分53秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int m,num[100005] = {0}, k, s;
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> num[i];
    }
    cin >> k >> s;
    int f = s - k;
    int l = 0,r = m - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (num[mid] == f) {
            cout << "Yes" <<endl;
            return 0;
        }
        if (num[mid] < f) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << "No" << endl;
    return 0;
} 

