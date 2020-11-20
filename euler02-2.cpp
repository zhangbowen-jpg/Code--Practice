/*************************************************************************
	> File Name: euler02-2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月31日 星期三 16时09分16秒
 ************************************************************************/

#include <stdio.h>
#define max_n 4000000

int fib[3] = {0,1};

int main() {
    int n = 1;
    int sum = 0;
    while (fib[n % 3] + fib[(n-1) % 3] < max_n) {
        n += 1;
        fib[n % 3] = fib[(n - 1) % 3] + fib[(n - 2) % 3];
        if (!(fib[n % 3] & 1)) sum += fib[n % 3];
    }
    printf("%d\n",sum);
    return 0;
}
//fib[n % 3] & 1 表示判断奇偶。
