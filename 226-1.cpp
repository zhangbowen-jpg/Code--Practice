/*************************************************************************
	> File Name: 226-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月23日 星期五 14时57分01秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<vector>
using namespace std;

long long pow(long long a, long long b,long long p) {
    long long res = 1;
    while(b) {
        if (b & 1) res = res * a % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return res % p;
}
int main() {
    int a,b,cnt;
    cin >> a >> b >> cnt;
    cout << pow(a,b,cnt) << endl;
}

