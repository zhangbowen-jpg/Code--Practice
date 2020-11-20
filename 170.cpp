/*************************************************************************
	> File Name: 170.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月09日 星期五 19时40分25秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string ans;
        cin > ans;
        while (ans.find("Ban_smoking") != -1) {
            int pos = ans.find("Ban_smoking");
        ans.replace(pos, 11, "No_smoking");
        }
        cout << str << endl;
    }
    return 0;
}

