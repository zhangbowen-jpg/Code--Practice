/*************************************************************************
	> File Name: 116c++.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月28日 星期日 12时11分09秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int a, b, c, f;
    cin >> a >> b >> c;
    if (a > c) swap(a,c);
    if (b > c) swap(b,c);
    f = c * c - a * a - b * b;
    if(a + b < c) {
        cout << "illegal triangle" << endl;
    } else if (f < 0) {
        cout << "acute triangle" << endl;
    } else if (f == 0) {
        cout << "right triangle" << endl;
    } else {
        cout << "obtuse triangle" << endl;
    }
    return 0;
}
