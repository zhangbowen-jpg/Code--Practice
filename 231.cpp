/*************************************************************************
	> File Name: 231.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月15日 星期四 01时43分23秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int arr[17] = {0,1,3};

int main() {
    int n;
    scanf("%d",&n);
    for(int i = 3; i <= 12; i++) {
        int val;
        int sum = 1000000;
        for(int j = 1; j < i; j++) {
            val = 2 * arr[j] +((int)pow(2,i - j)) - 1;
            if(sum > val) sum = val;
        }
        arr[i] = sum;
    }
    printf("%d",arr[n]);
    return 0;
}

