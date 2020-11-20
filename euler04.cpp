/*************************************************************************
	> File Name: euler04.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月02日 星期五 14时31分51秒
 ************************************************************************/

#include <stdio.h>

int is_val(int x,int base) {
    int tmp = x,sum = 0;
    while (x) {
        sum = sum * base + x % base;
        x /= base;
    }
    return sum == tmp;

}

int main() {
    int ans = 0;
    for(int a = 100; a < 1000; a++) {
        for(int b = ans / a + 1; b <= a; b++) {
            if(is_val(a * b, 10) && ans < a * b) ans = a * b;
        }
    }
    printf("%d\n", ans);
    return 0;
}
