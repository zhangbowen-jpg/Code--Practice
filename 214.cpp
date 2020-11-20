/*************************************************************************
	> File Name: 214.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月21日 星期三 14时18分20秒
 ************************************************************************/

#include<stdio.h>
#define max_n 30

int num[max_n + 5];

int main() {
    int n,temp,m;
    double ans;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d",&num[i]);
    }
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(num[i] < num[j]) {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        ans += num[i];
    }
    ans /= m;
    printf("%.2f",ans);
    return 0;
}

