/*************************************************************************
	> File Name: 200.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月12日 星期一 14时14分35秒
 ************************************************************************/

#include<stdio.h>

int arr[30 + 5] = {0};

int ditui(int x) {
    if(arr[x] == 0)
    arr[x] = ditui(x - 1) + ditui(x - 2);
    return arr[x];
}

double answer(int n) {
    double ans = 0;
    double a,b;
    for(int i = 1; i <= n; i++){
        a = ditui(i - 1);
        b = ditui(i);
        ans += (a / b);
    }
    return ans;
}

int main() {
    int n;
    double ans;
    arr[0] = 4;
    arr[1] = 7;
    scanf("%d", &n);
    printf("%d/%d\n",ditui(n - 1),ditui(n));
    printf("%.2f",answer(n));
    return 0;
}

