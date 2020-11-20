/*************************************************************************
	> File Name: 266.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月07日 星期日 14时00分27秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
#define INF 0x3f3f3f3f

int calc(char *str, int l, int r) {
    int pos = -1, pri = INF, temp = 0;
    for (int i = l; i < r; i++) {
        int cur_pri = INF + 1;
        switch (str[i]) {
            case '(': temp += 100; break;
            case ')': temp -= 100; break;
            case '+': 
            case '-': cur_pri = temp + 1; break;
            case '*':
            case '/': cur_pri = temp + 2; break;
            case '^': cur_pri = temp + 3; break;
        }
        if (cur_pri <= pri) {
            pos = i;
            pri = cur_pri;
        }
    }
    if (pos == -1) {
        int num = 0;
        for (int i = l; i < r; i++) {
            if (str[i] < '0' || str[i] > '9') continue;
            num = num * 10 + str[i] - '0';
        }
        return num;
    }
    int a = calc(str, l, pos);
    int b = calc(str, pos + 1, r);
    switch (str[pos]) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return (int)pow(a, b);
    }
    return 0;
}

int main() {
    char str[1000];
    while (cin >> str) {
        cout << calc(str, 0, strlen(str)) << endl;
    }
    return 0;
}
