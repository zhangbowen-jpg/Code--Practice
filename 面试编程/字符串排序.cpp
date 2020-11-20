/*************************************************************************
	> File Name: 字符串排序.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月17日 星期一 18时00分05秒
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n]; //记录数字
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        char s[6];
        for(int j = 0; j < 6; j++) {
            s[j] = str[j + str.length() - 6];
            int tmp = atoi(s);
            arr[i] = tmp;
        }
    }
        sort(arr, arr + n);
        for(int j = 0; j < n; j++) {
            cout << arr[j] << endl;
        }
    return 0;
}
