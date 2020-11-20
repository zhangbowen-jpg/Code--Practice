/*************************************************************************
	> File Name: 173.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月06日 星期二 15时33分24秒
 ************************************************************************/

#include<stdio.h>

int main() {
    char arr[1000];
    int i,sum1 = 0,sum2 = 0,sum3 = 0,sum4 = 0,sum = 0;
    for(i = 0; i <= 999; i++) {
        scanf("%c",&arr[i]);
        sum++;
        if(arr[i] == '\n') break;
    }
    for(i = 0; i < sum - 1; i++) {
        if(((arr[i] >= 'A') && (arr[i] <= 'Z')) || ((arr[i] >= 'a') && (arr[i] <= 'z'))) sum1++;
        else if((arr[i] >= '0') && (arr[i] <= '9')) sum2++;
        else if(arr[i] <= ' ') sum3++;
        else sum4++;
}
    printf("%d %d %d %d",sum1,sum2,sum3,sum4);
}

