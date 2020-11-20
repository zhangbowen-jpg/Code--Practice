/*************************************************************************
	> File Name: 534.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月09日 星期一 19时47分04秒
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
#define MAX_N 20
int V[MAX_N + 5];
bool arr[1005] = {0};

void dfs(int n, int num, int sum) {
    if(num > n) {  //到底了
        arr[sum] = true;
        return ;
    }
    dfs(n, num + 1, sum + V[num]);   //取
    dfs(n, num + 1, sum);   //不取
}

int main() {
    int n, sum = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> V[i];
    }
    dfs(n, 1, 0);    //从第一个物品开始，总和为零
    for(int i = 1; i <= 1004; i++) {
        if(arr[i]) sum++; //如果对应位置有结果 ++
    }
    cout << sum << endl; 
    return 0;
}


