/*************************************************************************
	> File Name: 字符串归一化.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月17日 星期一 17时59分42秒
 ************************************************************************/
#include<iostream>
#include<string.h>
using namespace std;

int main() {
    int dic[26] = {0};
    char str;
    while((str = getchar()) != '\n') {
        dic[str - 'a']++;
    }
    for(int i = 0; i < 26; i++) {
        if(dic[i] != 0) cout << (char)('a'+ i) << dic[i];
    }
    return 0;
}
