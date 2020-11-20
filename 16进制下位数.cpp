/*************************************************************************
	> File Name: 16进制下位数.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月15日 星期日 14时36分06秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main() {
    char str[10];
    int n;
    while(~scanf("%d",&n)) {
        sprintf(str,"%x", n);
        printf("%s has %lu digits\n", str, strlen(str));
    }
    return 0;
}

