/*************************************************************************
	> File Name: euler07-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月05日 星期一 15时27分46秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define max_n 200000

int prime[max_n + 5];

int main() {
    memset(prime, 0, sizeof(prime));//初始化数组为0
    for(int i = 2; i <= max_n; i ++) {
        if (!prime[i]) {  //等同于prime[i]==0
            prime[++prime[0]] = i;
            for (int j = 2; j * i <= max_n; j++) {
                prime[j * i] = 1;//i的倍数是合数，标记为1
            }
        }
    }
    printf("%d\n", prime[10001]);
    return 0;
}

