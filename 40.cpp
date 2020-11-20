/*************************************************************************
	> File Name: 40.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月09日 星期二 15时37分33秒
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
    BigInt operator+(BigInt &b) {
        BigInt c(*this);
        for (int i = 0; i < b.num.size(); i++) {
            if (i == c.num.size())  c.num.push_back(0);
            c.num[i] += b.num[i];
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
    }
    vector<int> num;
};

ostream &operator<<(ostream &out, BigInt &b) {
    for (int i = b.num.size() - 1; i >= 0; --i) {
        out << b.num[i];
    }
    return out;
}
void solve(int n) {
    BigInt a(0), b(1), c(1), d(0);
    if (n == 1) cout << a << endl;
    else if (n == 2) cout << b << endl;
    else if (n == 3) cout << c << endl;
    else {
        n -= 3;
        while (n--) {
            d = a + b;
            a = b;
            b = c;
            c = d;
        }
        cout << c << endl;
    }
    return ;
}

int main() {
    int n;
    while (cin >> n) solve(n);
    return 0;
}
