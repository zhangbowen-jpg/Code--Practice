/*************************************************************************
	> File Name: 40-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月14日 星期三 20时03分59秒
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cinttypes>
#define max_n 500
using namespace std;

int arr[max_n + 5][100] = {{1, 0}, {1, 0}, {1, 1}, {1, 1}};

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 4; i <= max_n; i++) {
        arr[i][0] = arr[i - 3][0] > arr[i - 2][0] ? arr[i - 3][0] : arr[i - 2][0];
        for (int j = 1; j <= arr[i][0]; j++) {
            arr[i][j] = arr[i - 3][j] + arr[i - 2][j];
        }
        for (int j = 1; j <= arr[i][0]; j++) {
            if (arr[i][j] < 10) continue;
            arr[i][j + 1] += arr[i][j] / 10;
            arr[i][j] %= 10;
            arr[i][0] += (j == arr[i][0]);
        }
    }
    for (int i = arr[n][0]; i > 0; i--) {
        printf("%d", arr[n][i]);
    }
    return 0;
}    
   

