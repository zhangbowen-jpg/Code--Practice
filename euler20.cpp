/*************************************************************************
	> File Name: euler20.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月14日 星期三 16时41分31秒
 ************************************************************************/

#include<stdio.h>
#define max_n 10000

int arr[max_n + 5] = {0};

int main() {
    arr[0] = arr[1] = 1;
    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= arr[0]; j++) {
            arr[j] *= i;
    }
        for(int k = 1; k <= arr[0]; k++) {
            if(arr[k] < 10) continue;
            arr[k + 1] += arr[k] / 10;
            arr[k] %= 10;
            arr[0] += (k == arr[0]);
        } 
    }
    int sum = 0;
    for(int i = arr[0]; i >= 1; i--) {
        sum += arr[i];
    }
    printf("%d",sum);
    return 0;

}

