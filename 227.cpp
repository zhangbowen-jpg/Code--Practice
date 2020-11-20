/*************************************************************************
	> File Name: 227.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月03日 星期六 09时00分43秒
 ************************************************************************/

#include<iostream>
using namespace std;

typedef long long ll;
int main() {
    ll a,b,p;
    cin >> a >> b >> p;
    ll res = 0;
    while(a) 
    {
        if(a & 1){
            res = (res + b) % p;
        }
        a = a >> 1;
        b = 2 * b % p;
    }
    cout << res << endl;
    return 0;
}

