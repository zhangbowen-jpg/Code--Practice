/*************************************************************************
	> File Name: 144.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月28日 星期日 16时19分32秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main() {
    string str;
    cin >> str;
    int ans = 0;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == 'A') {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

