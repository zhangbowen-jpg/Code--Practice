/*************************************************************************
	> File Name: 199.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月21日 星期三 20时38分04秒
 ************************************************************************/

#include<stdio.h>
#define max_n 100000

long long arr[max_n + 5] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int a[11];

long long ditui(long long x) {
    return a[1] * arr[x - 1] + a[2] * arr[x - 2] + a[3] * arr[x - 3] + a[4] * arr[x - 4] + a[5] * arr[x - 5] + a[6] * arr[x - 6] + a[7] * arr[x - 7] + a[8] * arr[x - 8] + a[9] * arr[x - 9] + a[10] * arr[x - 10];
}

int main() {
    long long k,m,ans;
    scanf("%lld%lld",&k,&m);
    for(int i = 1; i <= 10; i++) {
        scanf("%d",&a[i]);
    }
    for (int i = 10; i <= k; i++){
        arr[i] = ditui(i) % m;
    }    
    printf("%lld",arr[k]);
    return 0;
}

