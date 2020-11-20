/*************************************************************************
	> File Name: 188.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月05日 星期一 17时55分09秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define max_n 1000000

int prime[max_n + 5] = {0};

void init() {
    for(int i = 2; i <= max_n; i++) {
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j<= prime[0]; j++) {
            if(i * prime[j] > max_n) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}

int main() {
    int m,n;
    init();
    cin >> m >> n;
    for(int i = 1; i <= prime[0]; i++) {
        if(prime[i] >= n && prime[i] <= m) printf("%d\n",prime[i]);    
    }
    return 0;

}

