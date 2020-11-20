/*************************************************************************
	> File Name: 155.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月27日 星期六 16时43分57秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n,m = 3,sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        m = m + 2*i;
        sum += m;
        printf("%d\n",m);
    }
    printf("%d",sum);
    return 0;
}

