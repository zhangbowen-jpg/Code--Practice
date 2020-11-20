/*************************************************************************
	> File Name: 扩展欧几里得.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月07日 星期日 13时40分43秒
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

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int ex_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int r = ex_gcd(b, a % b, y, x);
    y -= a / b * x;
    return r;
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        int x, y, r;
        r = ex_gcd(a, b, x, y);
        cout << "rest : " << r << endl;
        printf("%d * %d + %d * %d = %d\n", a, x, b, y, a * x + b * y);
    }
    return 0;
}
