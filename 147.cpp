/*************************************************************************
	> File Name: 147.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月02日 星期五 20时53分56秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main() {
    string str;
    cin >> str;
    if (((str[str.size() - 1]) - '0') % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" <<endl;
    }
    return 0;
}

