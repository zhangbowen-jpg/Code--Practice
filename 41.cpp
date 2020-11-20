/*************************************************************************
	> File Name: 41.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月09日 星期二 15时42分04秒
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

struct BigInt {
    BigInt(int x) {
        num.push_back(x);
        proccess_digit();
    }
    BigInt operator+(BigInt &&b) {
        BigInt c(*this);
        for (int i = 0; i < b.num.size(); i++) {
            if (i == c.num.size())  c.num.push_back(0);
            c.num[i] += b.num[i];
        }
        c.proccess_digit();
        return c;
    }
    BigInt operator*(int x) {
        BigInt c(*this);
        for (int i = 0; i < c.num.size(); i++) {
            c.num[i] *= x;
        }
        c.proccess_digit();
        return c;
    }
    void proccess_digit() {
        for (int i = 0; i < num.size(); i++) {
            if (num[i] < 10) continue;
            if (i + 1 == num.size()) num.push_back(0);
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
        while (num.size() > 1 && num[num.size() - 1] == 0) {
            num.erase(num.begin() + num.size() - 1);
        }
        return ;
    }
    vector<int> num;
};

ostream &operator<<(ostream &out, BigInt &b) {
    for (int i = b.num.size() - 1; i >= 0; --i) {
        out << b.num[i];
    }
    return out;
}
void solve(int n, int k) {
    BigInt a(k), b(k * (k - 1)), c(k * (k - 1) * (k - 2)), d(0);
    if (n == 1) cout << a << endl;
    else if (n == 2) cout << b << endl;
    else if (n == 3) cout << c << endl;
    else {
        n -= 3;
        while (n--) {
            d = c * (k - 2) + b * (k - 1);
            b = c;
            c = d;
        }
        cout << c << endl;
    }
    return ;
}

int main() {
    int n, k;
    while (cin >> n >> k) solve(n, k);
    return 0;
}
