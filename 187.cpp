/*************************************************************************
	> File Name: 187.cpp
	> Author: 
	> Mail: 
    > Created Time: 2019年08月09日 星期五 19时42分21秒
 ************************************************************************/
#include<iostream>
using namespace std;

long long f1(long long n) {
    if (n == 1) return 1;
    return 2 * f1(n - 1) + 1;
}

long long f2(long long n) {
    if (n == 1) return 1;
    return 2 * f2(n - 1) + n;
}

int main() {
    long long n;
    cin >> n;
    cout << f1(n) << " " << f2(n) << endl;
    return 0;
}

