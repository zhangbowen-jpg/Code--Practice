/*************************************************************************
	> File Name: 313.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月19日 星期一 18时07分16秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int n;
    int k;
    scanf("%d%d",&n,&k);
    int sum = 0;
    if(n > k){
    for(int i = 1; i < k; i++) {
        sum += (k % i);
    }
    sum += k * (n - k);
}
    else {
    for(int i = 1; i <= n; i++) {
        sum += (k % i);
    }
    }
    printf("%lld",sum);
    return 0;
}

