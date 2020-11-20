/*************************************************************************
	> File Name: 177.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月03日 星期六 18时00分47秒
 ************************************************************************/

#include<stdio.h>

int main() {
    char a[26];
    int sum = 0;
    for(int i = 0; i < 26; i++) {
        scanf("%c",&a[i]);
        if(a[i] == '\n') break;
        sum++;
    }
    for(int i = 0; i < sum; i++) {
        for(int j = 0; j < sum; j++) {
            printf("%c",a[(j+(sum-2)*i)%sum]);
        }
        printf("\n");
    }
    return 0;
}

