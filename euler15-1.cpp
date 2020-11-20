/*************************************************************************
	> File Name: euler15-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月14日 星期三 16时15分26秒
 ************************************************************************/

#include<stdio.h>

int main() {
    long long n = 40, m = 20, ans = 1;
    while (m > 1) {
        if(n > 20) ans *= (n--);
        if(m && ans % m == 0) ans /= (m--);
    } 
    printf("%lld\n",ans);

    return 0;
}

