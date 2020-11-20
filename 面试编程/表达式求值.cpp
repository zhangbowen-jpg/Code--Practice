/*************************************************************************
	> File Name: 表达式求值.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月14日 星期五 14时00分33秒
 ************************************************************************/
#include<iostream>
using namespace std;

int max_1(int a, int b) {
    return max(a + b, a * b);
}

int max_2(int a, int b, int c) {
    return max(max_1(a, max_1(b, c)), max_1(max_1(a, b), c));
}

int main() {
    int a, b ,c;
    cin >> a >> b >> c;
    cout << max_2(a, b, c) << endl;
    return 0;
}
