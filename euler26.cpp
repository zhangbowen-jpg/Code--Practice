/*************************************************************************
	> File Name: euler26.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月16日 星期五 15时56分03秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
#define max_n 1000

int keep[max_n + 5];//记录出现这个余数的时间点

int get_len(int x) {
    memset(keep, 0, sizeof(keep));
    int r = 1, t = 1; 
    keep[1] = 1;
    while (r) {
        r *= 10;
        r %= x;
        t += 1;
        if (keep[r]) return t - keep[r];
        keep[r] = t;
    }
    return 0;
}

int main() {
    int d = 0, len = 0;
    for (int i = 1; i < max_n; i++) {
        int temp = get_len(i);
        if (temp > len) {
            len = temp;
            d = i;
        }
    }
    cout << d << " " << len << endl;
    return 0;
}

