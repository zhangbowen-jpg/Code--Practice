/*************************************************************************
	> File Name: 191.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月05日 星期一 20时18分57秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#define max 8000000
using namespace std;

int prime[max + 5] = {1,1};

int init() {
    for(int i = 2; i * i <= max; i++) {
        if(!prime[i]) { 
        for (int j = 2; i * j <= max; j++) {
            prime[i * j] = 1;
    }
}
    }
}
int main() {
    int n,m;
    cin >> n >> m;
    init();
    int min1 = -1, min2, max1, max2;
    for(int i = n; i < m; i++) {
        if(!prime[i]) {
            int nex = i + 1;
            while (prime[nex]) {
                nex++;
            }
        if (nex > m) {
            break;
        }
        if (min1 == -1) {
            min1 = max1 = i;
            min2 = max2 = nex;
        } else if (min2 - min1 > nex - i) {
            min1 = i;
            min2 = nex;
        } else if (max2 - max1 < nex -i) {
            max1 = i;
            max2 = nex;
        }
        }
    }
    if(min1 == -1) {
        printf("There are no adjacent primes.");
    } else {
        printf("%d,%d are closest, %d,%d are most distant.",min1,min2,max1,max2);
    }
    return 0;
}

