/*************************************************************************
	> File Name: 回文字符串.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月17日 星期一 18时00分35秒
 ************************************************************************/
#include<iostream>
#include<string.h>
using namespace std;
#define MAX_N 1000

int arr[MAX_N + 5][MAX_N + 5];
char str[MAX_N + 5];

//使用arr[i][j]来表示两个字符之间的最大回文字串长度
//若str中有相同字符，记录最大长度arr[i+1][j-1]+2，否则记录最大值
int main() {
    int len;
    cin >> str;
    len = strlen(str);
    for(int i = 0; i < len; i++) {
        arr[i][i] = 1;
        for(int j = i - 1; j >= 0; j--) {
            if(str[i] == str[j]) {
                arr[j][i] = arr[j + 1][i - 1] + 2;
            } else {
                arr[j][i] = max(arr[j + 1][i], arr[j][i - 1]);
            }
        }
    }
    cout << arr[0][len - 1] << endl;
    return 0;
}
