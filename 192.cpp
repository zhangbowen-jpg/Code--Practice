/*************************************************************************
	> File Name: 192.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月10日 星期六 15时32分51秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

double f(double x) {
    return x * exp(x);
}

int main() {
    double a;
    cin >> a;
    double l = 0, r = 30;
    while (r - l > 0.000001) {
        double mid = (l + r) / 2;
        if (f(mid) > a) {
            r = mid;
        } else {
        l = mid;
        }
    }
    printf("%.4f\n", l);
    return 0;
}

