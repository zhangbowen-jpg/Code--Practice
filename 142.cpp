/*************************************************************************
	> File Name: 142.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 20时01分47秒
 ************************************************************************/

#include<stdio.h>

int isvaild(int n) {
    for(int i=2; i < n; i++) {
        if (n%i==0) return false;
        else continue;
    }
    return true;
}


int main() {
    int a, b, n = 0;
    scanf("%d%d", &a, &b);
    for (int i = a; i <= b; i++) {
    if ((i/10000==i%10)&&((i%10000)/1000==(i%100)/10)){
        if (isvaild(i)) {
            if (n==1){
                printf(" ");
            }
        printf("%d", i);
        n = 1;
        }
    }
    }
    return 0;
}

