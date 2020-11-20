/*************************************************************************
	> File Name: 172.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月02日 星期五 19时23分48秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    string s[10];
    for(int i = 0; i < 10; i++) {
        cin >> s[i];
    }
    sort(s, s + 10);
    for(int i = 0; i < 10; i++) {
        cout << s[i] << endl;
    }
    return 0;
}

