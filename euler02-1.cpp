/*************************************************************************
	> File Name: euler02-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月31日 星期三 15时50分52秒
 ************************************************************************/

#include<stdio.h>
#define max_n 4000000

int main() {
    int a = 1,b = 2;
    int sum = 2;
    while(a + b < max_n) {
        b = a + b;
        a = b - a;
        if(!(b & 1)) {
            sum += b;
        }
    } 
    printf("%d\n",sum);
    return 0;
}
// 将和付给后面的值，将这一项的值给前一项；
