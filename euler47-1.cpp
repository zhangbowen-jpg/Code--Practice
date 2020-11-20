/*************************************************************************
	> File Name: euler47-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月16日 星期五 19时58分56秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<vector>
using namespace std;
#define max_n 1000000

int prime[max_n + 5] = {0};

void init() {
    for(int i = 2; i<= max_n; i++) {//注意：这是素数筛
        if(prime[i]) continue;
        for(int j = i; j <= max_n ; j+=i) {
            prime[j] += 1;
        }
    }
    return ;
}

int main() {
    init();
    for(int i = 2; i < max_n; i++) {
        int flag = 1;
        for (int k = 0; k < 4 && flag; k++) {
            flag = (prime[i + k] == 4);
        }
        if(flag) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}


