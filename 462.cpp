/*************************************************************************
	> File Name: 462.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月12日 星期一 16时28分35秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
#define max_n 10000

long long qq[max_n + 5];
char id[max_n + 5][20];

int get_num(int x, int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int len = strlen(id[i]);
        if ((id[i][len - 2] - '0') % 2 == x) cnt++;
    }
    return cnt;
}

long long get_avg(int n) {
    if (n == 0) return 0;
    long long sum = 0,ans = 0;
    for (int i = 0; i < n; i++) {
        sum = qq[i];
        ans += sum;
    }
    return ans / n;
}

int main() {
    int n;
    cin >> n;
    getchar();
    char ch;
    int k = 0, t = 0;
    for(int i = 0; i < n; i++) {
        cin >> ch;
        if(ch == 'i') {
            cin >> id[k++];
        } else {
            cin >> qq[t++];
        }
    }
    int man_cnt = get_num(1, k);
    int women_cnt = get_num(0, k);
    long long avg = get_avg(t);
    cout << man_cnt << " " << women_cnt << " " << avg << endl;
    return 0;
}

