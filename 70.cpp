/*************************************************************************
	> File Name: 70.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月22日 星期四 22时26分40秒
 ************************************************************************/

#include<iostream>
using namespace std;

int arr[1000] = {0};

bool is_vaild(int n) {
    if(n % 2 == 0) {
        n /= 2;
        return is_vaild(n);
    }
    if(n % 3 == 0) {
        n /= 3;
        return is_vaild(n);
    }
    if(n % 5 == 0) {
        n /= 5;
        return is_vaild(n);
    }
    if(n == 1) return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    cout << "1" << endl;
    for(int i = 2; i <= n; i++) {
        if (is_vaild(i)) cout << i << endl;
    }
    return 0;
}

