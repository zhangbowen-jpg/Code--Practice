/*************************************************************************
	> File Name: euler46.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月16日 星期五 18时54分16秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<vector>
using namespace std;
#define max_n 100000

int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {0};

void init() {//线性筛
    for (int i = 2; i <= max_n; i++) {
        if(!is_prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++) {
            if(prime[j] * i > max_n) break;
            is_prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) break;
        }
    }
    return ;
}

int func(int n) {//2乘素数的平方
    return 2 * n * n;
}

bool binary_search(int (*f)(int), int l, int r, int x) {//二分法传入函数找值
    if (l > r) return false;
    int mid = (l + r) >> 1;
    if (f(mid) == x) return true;
    if (f(mid) < x) l = mid + 1;
    else r = mid - 1;
    return binary_search(f, l, r, x);

}

int is_vaild(int x) {//判断是否满足
    //x - prime[i] = 2 * n * n
    for (int i = 1; i <= prime[0] && prime[i] < x; i++) {
        int val = x - prime[i];
        if (binary_search(func, 1, val, val)) return true;
    }
    return false;
}

int main() {
    init();
    for (int i = 9; i <= max_n; i+=2) {
        if(!is_prime[i]) continue;//判断素数
        if(is_vaild(i)) continue;//如果是这种数就跳过
        cout << i << endl;
        break;
    }
    return 0;           
}

