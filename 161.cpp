/*************************************************************************
	> File Name: 161.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月27日 星期六 15时59分04秒
 ************************************************************************/

#include <stdio.h>
int main() {
    int x,n;
    scanf("%d%d",&x,&n);
    double sum = x;
    for(int i = 1; i <= n; i++) {
        sum = sum * (1.06); 
    }
    printf("%lf", sum);
    return 0;

}

