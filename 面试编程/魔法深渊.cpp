/*************************************************************************
	> File Name: 魔法深渊.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月17日 星期一 17时58分47秒
 ************************************************************************/
#include <iostream>
using namespace std;
#define MAX_N 1000000000 + 3

void init(long long n[]) {
    for(int i = 1; i <= 1000; i++)
    {
        long long sum = 0;
        for(int j = 1; j <= i; j <<= 1)
        {
            sum += n[i-j];
            sum = sum %= MAX_N;
        }
        n[i] = sum;
    }
    return ;
}
 
int main() {
    long long n[1001] = {0};
    n[0] = 1;
    init(n);
    int tmp, m;
    cin >> m;
    while(m--) {
        cin >> tmp;
        cout << n[tmp] << endl;
    }
    return 0;
}
