/*************************************************************************
	> File Name: 467-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月12日 星期一 20时29分03秒
 ************************************************************************/

#include<stdio.h>

int arr[30] = {1,1};

int main() {
    int n; 
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1, j <= 30; j++) {
            arr[j] =  arr[j] * i;
            if(arr[j] < 10) continue;
            arr[j] = arr[j] % 10；
            arr[j + 1] += 1;
        }
    }

}
