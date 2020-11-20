/*************************************************************************
	> File Name: 439.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年09月29日 星期日 20时38分07秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<math.h>
#include<cstdio>
using namespace std;

int main() {
    double x,y = 2,z = 0;
    scanf("%lf",&x);
    for(int i = 0; i <= 1000; i++) {
        z = z + y;
        y = y * 0.98;
        if(z >= x) {
            printf("%d",i + 1);
            break;
        }
    }
    return 0;
}



