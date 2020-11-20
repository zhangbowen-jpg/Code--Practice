/*************************************************************************
	> File Name: 181.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月02日 星期五 20时30分42秒
 ************************************************************************/

#include<stdio.h>
#define MAX_N 1000000
int main() {
    char arr[MAX_N+5];
    int sum = 0;
    for(int i = 0; i < MAX_N; i++) {
        scanf("%c",&arr[i]);
        sum++;
        if(arr[i] == '\n') break;
        if(arr[i] >= 65 && arr[i] <= 90){
            arr[i] = arr[i] + 32;
        }
        else if(arr[i] >= 97 && arr[i] <= 122){
            arr[i] = arr[i] - 32;
        }
        else continue;
    }
    for(int i = 0; i < sum; i++) {
        printf("%c",arr[i]);
    }
    return 0;
}

