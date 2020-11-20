/*************************************************************************
	> File Name: euler10.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月31日 星期三 15时04分32秒
 ************************************************************************/

#include <stdio.h>

int is_vaild(int n) {
    for(int i = 2; i < n ; i++) {
        if(n%i == 0) return false;
    }
    return true;
}

int main() {
    long long sum = 2;
    for(int i = 3; i < 2000000; i++) {
        if(is_vaild(i)) {
            sum += i;
        }
    }
    printf("%lld",sum);
    return 0;
}

