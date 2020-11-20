/*************************************************************************
	> File Name: 166.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月17日 星期六 16时51分25秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main() {
    string a, b;
    int n;
    cin >> a >> n >> b;
    int j = 1;
    if (a.size() > 100) {
        cout << 100 << endl;
    } else {
        cout << a.size() << endl;
    }
    a = a.insert(n - 1, b);
    cout << a << endl;
    for (int i = a.size() - 1; i >= 0; i--, j++) {
        if (a[i] == 'x') {
            cout << j << endl;
            break;
        }
    }
    return 0;
}

