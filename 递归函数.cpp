/*************************************************************************
	> File Name: 递归函数.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月07日 星期日 13时27分49秒
 ************************************************************************/

#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int f(int n) {
    if (n <= 1) return 1;
    return n * f(n - 1);
}

int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}
