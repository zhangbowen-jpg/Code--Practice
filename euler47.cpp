/*************************************************************************
	> File Name: euler47.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月16日 星期五 19时30分16秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<vector>
using namespace std;
#define max_n 100000

int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {0};
int num[max_n + 5] = {0};

void init() {
    for(int i = 2; i < max_n; i++) {
        if(!prime[i]) prime[++prime[0]] = i,is_prime[i] = 1;
    for(int j = 1; j <= prime[0]; j++) {
        if(prime[j] * i > max_n) break;
        prime[prime[j] * i] = 1;
        if(i % prime[j] == 0) {
            a[prime[j] * i] = a[i];
            break;
        }
        else {
            a[prime[j] * i] = a[i] + 1;
        }
    }
    }
    return ;
}

int main() {
    init();
    for(int i = 1; i <= prime[0]; i++) {
        if(a[i] != 4) continue;
        if(a[i] )
    }

}
