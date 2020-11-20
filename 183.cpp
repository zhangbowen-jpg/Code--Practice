/*************************************************************************
	> File Name: 183.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月02日 星期五 18时47分54秒
 ************************************************************************/

#include<stdio.h>

int f(int x) {
    int temp;
   if(x <= 0) {
        temp = 0;
    } else if (x == 1) {
        temp = 1;
    } else if ((x > 1) && (x % 2 == 0)) {
        temp = 3*f(x/2)-1;
    } else {
        temp = 3*f((x+1)/2)-1;
    } 
    return temp;
}

int main() {
    int x,num;
    scanf("%d", &x);
    printf("%d",f(x));
    return 0;
}
