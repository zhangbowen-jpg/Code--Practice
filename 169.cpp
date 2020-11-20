/*************************************************************************
	> File Name: 169.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月18日 星期日 17时28分10秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main() {
    int n, num[128] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a;
        int b;
        cin >> a >> b;
        num[(int)a] = b;
    }
    string str;
    cin >> str;
    int ans = 0;
    for (int i = 0; i < str.size(); i++) {
        ans += num[(int)str[i]] ;
    }
    cout << ans << endl;
    return 0;
}

