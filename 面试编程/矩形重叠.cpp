/*************************************************************************
	> File Name: 矩形重叠.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月10日 星期一 18时42分48秒
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

struct Data {
    int x1, y1, x2, y2;
} arr[55];
map<int, int> indx, indy;

bool check(int k, int x, int y) {
    if (x < arr[k].x1 || x > arr[k].x2) return false;
    if (y < arr[k].y1 || y > arr[k].y2) return false;
    return true;
} //判断点是否在举行内部

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i].x1;
    for (int i = 0; i < n; i++) cin >> arr[i].y1;
    for (int i = 0; i < n; i++) cin >> arr[i].x2;
    for (int i = 0; i < n; i++) cin >> arr[i].y2;
    for (int i = 0; i < n; i++) {
        arr[i].x1 += 1, arr[i].y1 += 1;
        indx[arr[i].x1] = indx[arr[i].x2] = 0;
        indy[arr[i].y1] = indy[arr[i].y2] = 0;
    } //坐标散列
    int cntx = 0, cnty = 0;
    for (auto iter = indx.begin(); iter != indx.end(); iter++) {
        iter->second = (++cntx); //因为map自带排序功能，所以放入之后能够获得最值
    }
    for (auto iter = indy.begin(); iter != indy.end(); iter++) {
        iter->second = (++cnty);
    } //坐标冲映射
    for (int i = 0; i < n; i++) {
        arr[i].x1 = indx[arr[i].x1];
        arr[i].y1 = indy[arr[i].y1];
        arr[i].x2 = indx[arr[i].x2];
        arr[i].y2 = indy[arr[i].y2];
    }
    int ans = 0;
    for (int i = 1; i <= cntx; i++) {  //在新的矩形中找满足的点
        for (int j = 1; j <= cnty; j++) {
            int cnt = 0;
            for (int k = 0; k < n; k++) {
                if (check(k, i, j)) cnt += 1; //对每个点判断在几个矩形内部
            }
            ans = max(ans, cnt); //找最大值
        }
    }
    cout << ans << endl;
    return 0;
}

