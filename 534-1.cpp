/*************************************************************************
	> File Name: 534-1.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月18日 星期三 20时25分47秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;

int n, num[25], check[1005] = {1}, ans;

//使用memset数组全付成1不可行，因为memset按字节赋值，全1实际为-1

void func(int s, int sum) {
    if(check[sum] == 0) {
        ans++;
        check[sum] = 1;
    }
    for(int i = s; i <= n; i++) {
        sum += num[i];
        func(i + 1, sum);
        sum -= num[i];
    }

}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    func(0, 0);
    cout << ans << endl;
    return 0;
}

