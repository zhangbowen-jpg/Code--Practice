/*************************************************************************
	> File Name: 146.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月27日 星期六 15时00分34秒
 ************************************************************************/
#include<iostream>
#include<string>
using namespace std;

int main() {
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] >= 'a' && str[i] < 'z' || str[i] >= 'A' && str[i] < 'Z') {
            str[i]++;
        } else if (str[i] == 'z') {
            str[i] = 'a';
        } else if (str[i] == 'Z') {
            str[i] = 'A';
        }
    }
    cout << str << endl;
    return 0;
}

