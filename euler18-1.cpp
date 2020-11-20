/*************************************************************************
	> File Name: euler18-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月14日 星期三 19时15分47秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<vector>
using namespace std;
#define max_n 20

int val[max_n + 5][max_n + 5];

int main() {
    for (int i = 0; i < max_n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> val[i][j];
        }
    }
    for (int i = max_n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {   
            val[i][j] += max(val[i + 1][j], val[i + 1][j + 1]);
        }
    }
    cout << val[0][0] << endl;
    return 0;
}

