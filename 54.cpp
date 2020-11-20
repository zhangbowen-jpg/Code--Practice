/*************************************************************************
	> File Name: 54.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月15日 星期四 00时42分01秒
 ************************************************************************/

#include<cstdio>
#include<iostream>
#include<cstring>
#include<cinttypes>
#include<math.h>
#define max_n 3000

int JC[max_n + 5];
int LC[max_n + 5];

int main() {
    int x;
    while (scanf("%d",&x) != EOF) {
        memset(JC, 0, sizeof(JC));
        memset(LC, 0, sizeof(LC));
        JC[0] = LC[0] = 1;
        JC[1] = LC[1] = 1;
        for(int i = 1; i <= x; i++) {
            for(int j = 1; j <= JC[0]; j++) {
                JC[j] *= i;
            }
            for(int k = 1; k <= JC[0]; k++) {
                if(JC[k] < 10) continue;
                JC[k + 1] += JC[k] / 10;
                JC[k] %= 10;
                JC[0] += (k == JC[0]);
            }
        }
        for(int i = 1; i <= JC[0]; i++) {
            if(JC[i] == 0) continue;
            for(int j = 1; j <= LC[0]; j++) {
                LC[j] *= JC[i];
            }
            for(int k = 1; k <= LC[0]; k++) {
                if(LC[k] < 10) continue;
                LC[k + 1] += LC[k] / 10;
                LC[k] %= 10;
                LC[0] += (k == LC[0]);
            }
        }
        for(int i = LC[0]; i >= 1; i--){
            printf("%d",LC[i]);
        }
        printf("\n");
    }
    return 0;
}

