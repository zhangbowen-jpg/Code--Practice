/*************************************************************************
	> File Name: 171.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月22日 星期四 15时59分52秒
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main() {
    string str;
    cin >> str;
    int ling = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '0') {
            ling++;
        }
    }
    if (ling == str.size() - 1 && str[0] == '1') {
        for (int i = 1; i < str.size(); i++) {
            cout << 9;
        }
    } else {
        string str2 = str;
        reverse(str2.begin(), str2.end());
        for (int i = 0; i < str.size() / 2; i++) {
            cout << str[i] << endl;
        }
        for (int i = str.size() / 2; i < str.size(); i++) {
            cout << str2[i] << endl;
        }
    }
    return 0;
}

