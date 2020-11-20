/*************************************************************************
	> File Name: euler36.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月02日 星期五 18时52分58秒
 ************************************************************************/

#include<stdio.h>
int is_vaild2(int n) {
    int temp = n, x = n, sum = 0;
    while (x) {
        sum = sum * 2 + x % 2;
        x /= 2;
    }
    return sum == temp;

}

int is_vaild10(int n) {
    int temp = n, x = n, sum = 0;
    while (x) {
        sum = sum * 10 + x % 10;
        x /= 10;
    }
    return sum == temp;
}

int main() {
    int sum = 0;
    for(int i = 1; i <= 1000000; i++) {
        if(is_vaild10(i) && is_vaild2(i)) sum += i;
    }
    printf("%d\n",sum);


}

