/*************************************************************************
	> File Name: 134c++.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月28日 星期日 13时29分25秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    for(int i = ((a - 1) / 11 + 1) * 11,j = 0; i <= b; i += 11, j += 1) {
    j && cout << " ";
    }
    return 0;
}
