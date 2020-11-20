/*************************************************************************
	> File Name: 165.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月27日 星期六 16时09分37秒
 ************************************************************************/
#include <stdio.h>
#include <iostream>
#include <cmath>

int main() {
    long long c;
    cin >> c;
    int ans = 0;
    for(long long a = 1; a < c; a++){
        long long b = sqrt(c * c - a * a);
        if (a * a + b * b == c * c) {
            ans++;
        }
    }
    cout << ans / 2 << endl;
    return 0;
}

