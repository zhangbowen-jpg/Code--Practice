/*************************************************************************
	> File Name: 464.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月16日 星期五 14时00分55秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int x,y,sum = 0;
    scanf("%d%d",&x,&y);
    for(int i = x; i <= y; i++) {
        if((i % 400 == 0) || (i % 4 == 0 && (i % 100 != 0)))
        sum += 1;
    }
    printf("%d",sum);
    return 0;
}

