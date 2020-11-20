/*************************************************************************
	> File Name: 227-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月23日 星期五 15时40分22秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<vector>
using namespace std;

typedef long long ll;

ll n,m,p;

ll cheng(ll a, ll b, ll p) {
    ll ans = 0;
    for(; b; b >>= 1) {
        if(b & 1) ans = (ans + a) % p;
        a = a * 2 % p;
    }
    return ans;
}

int main() {
    cin >> n >> m >> p;
    cout << cheng(n,m,p) << endl;
    return 0;
}


