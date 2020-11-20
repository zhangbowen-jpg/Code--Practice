/*************************************************************************
	> File Name: 7.25.6.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 19时04分31秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    srand(time(0));
    int a, b;
    scanf("%d%d", &a, &b);
    if (a - b) {
        printf("not equal\n");
    } else {
        printf("equal\n");
    }
    if ((a++) && (b++)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
//当地一个条件为0时，b++不会执行（&&运算原理/短路原则）。
    if ((a++) || (b++)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    printf("a = %d b = %d",a,b);
    
    for (int i = 0; i < 10; i++) {
        i && printf(" ");  //等价于 if (i) printf(" ");
        printf("%d", i);
    }
    printf("\n");
    
    for(int i = 0; i < 10; i++) {
        int val = rand() % 100;
        i == 0 || printf(" ");
        printf("%d", val);
        cnt += !(val % 2);//等价于 cnt += val & 1
    }
    printf("\n");
    printf("odd num : %d", cnt);
    //    ch - '0'   '0':48  '1':49  '2':50      x & 15,== x % 48;
    do {
        digit += 1;
        n /= 10; 
    } while (n)
    
    return 0;
}

