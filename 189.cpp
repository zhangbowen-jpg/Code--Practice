/*************************************************************************
	> File Name: 189.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月03日 星期日 23时48分20秒
 ************************************************************************/
#include <stdio.h>
#define MAX_N 1000000

int numbers[MAX_N + 5];

int find_numbers(int ,int *,int);

int main() {
    int n;
    int k;
    int m;
    int i;

    // 反复读入数字和查找数字的数量
    while (scanf("%d%d", &n, &k) != EOF) {
        
        // 读入给定的数字
        for (i = 1; i <= n; i++) {
            scanf("%d", &numbers[i]);
        }

        for (int j = 0; j < k; j++) {
            scanf("%d", &m);
            printf("%d",find_numbers(m,numbers,n));
            if(j < k-1){
                printf(" ");
            }
        }
    }
    return 0;
}
int find_numbers(int m,int *numbers,int n){
    int head = 1,tail = n, mid;
    while(head <= tail){
        mid = (head + tail) >> 1;
        if(numbers[mid] == m) return mid;
        else if(numbers[mid]<m) head = mid + 1;
        else  tail = mid - 1;
    }
    return 0;
}
