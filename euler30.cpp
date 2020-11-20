/*************************************************************************
	> File Name: euler30.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月02日 星期五 16时16分46秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define max_n 354294

int is_val(int x) {
    int temp = x, sum = 0;
    while (x) {
        sum += (int)pow(x % 10, 5); 
        x /= 10;
    }
    return sum == temp;

}
int main() {
    int sum = 0;
    for(int i = 2; i <= max_n; i++) {
        if(is_val(i)) sum += i;
    }
    printf("%d\n", sum);
    return 0;
}

