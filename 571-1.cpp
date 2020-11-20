/*************************************************************************
	> File Name: 571-1.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月07日 星期四 09时29分56秒
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string.h>
#include<set>
#include<vector>
#include<map>
using namespace std;
#define MAX_N 100

int imfriend[MAX_N + 5][MAX_N + 5];

struct Fr {
	int x, y, val;
	Fr(int a, int b, int c) {
		x = a, y = b, val = c;
	}
	
};

struct cmp {
	bool operator()(const Fr &a, const Fr &b) const {
		if(a.x - b.x) return a.x < b.x;
		if(a.val < b.val) return a.val < b.val;
		return a.y < b.y;
	}
};

set<Fr, cmp> s;


int main() {
	int n, x, y;
	cin >> n >> x >> y;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> imfriend[i][j];
			if(imfriend[i][j]) {
				s.insert(Fr(i, j, 1));
			}
		}
	}
	while(s.size()) {
		int x = s.begin()->x;
		int y = s.begin()->y;
		int num = s.begin()->val;
		s.erase(s.begin());
		for(int i = 1; i <= n; i++) {
			if(imfriend[y][i] != 1) continue;
			if(imfriend[x][i]) continue;
			imfriend[x][i] = num + 1;
			s.insert(Fr(x, i, num + 1));
		}
	}
	cout << imfriend[x][y] - 1 << endl;
 	return 0;
}






