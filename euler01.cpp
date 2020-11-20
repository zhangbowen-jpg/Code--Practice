/*************************************************************************
	> File Name: euler01.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月31日 星期三 14时53分49秒
 ************************************************************************/

#include<stdio.h>

int is_val(int x) {
    if(x % 3 == 0 || x % 5 == 0) return 1;
    return 0;
}

int main() {
    int sum = 0;
    for (int i = 1; i < 1000; i++) {
        if (is_val(i)) sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
