/*************************************************************************
	> File Name: euler31.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月09日 星期五 14时12分44秒
 ************************************************************************/

#include <stdio.h>
#define max_m 8 
#define max_n 200

int w[max_m + 5] = {1, 2, 5, 10, 20, 50, 100, 200};
//f(i, j) = f(i - 1, j) + f(i, j - w[i])
int f[2][max_n + 5];

int main() {
    for(int k = 0; k < max_m; k++) {
        int i = k % 2;
        f[i][0] = 1;
        for(int j = 1; j <= max_n; j++) {
            f[i][j] = f[i ^ 1][j];
            if(j - w[i] >= 0) f[i][j] += f[i][j - w[k]];
        } 
    }    
    printf("%d\n", f[(max_m - 1) % 2][max_n]);
    return 0;
}

