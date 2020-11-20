/*************************************************************************
	> File Name: euler34.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月02日 星期五 18时04分54秒
 ************************************************************************/

#include<stdio.h>
#define max_n 2540160

int num[10];

void init(int *num) {
    num[0] = 1;
    for(int i = 1; i < 10; i++) {
        num[i] = num[i-1] * i;
    }
    return ;
}

/*int jiecheng(int z) {
    int m = 1;
    for(int i = 1; i <= z; i++) {
        m *= i;
    }
    return m;
}
*/

int is_vaild(int n) {
    int temp = n, x = n,sum = 0;
    while(x) { 
        sum += num[x % 10];
        x /= 10;
    }
    return sum == temp;
}

int main() {
    int sum = 0;
    init(num);
    for(int i = 10; i <= max_n; i++) {
        if(is_vaild(i)) sum += i;
    }
    printf("%d\n",sum);
    return 0;
}

