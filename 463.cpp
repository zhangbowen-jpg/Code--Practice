/*************************************************************************
	> File Name: 463.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月21日 星期一 20时40分58秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;

struct Windows {
    int lx;
    int rx;
    int uy;
    int dy;
}; 

int main() { 
    Windows windows1,windows2; 
    scanf("%d%d%d%d", &windows1.lx, &windows1.rx, &windows1.uy, &windows1.dy);
    scanf("%d%d%d%d", &windows2.lx, &windows2.rx, &windows2.uy, &windows2.dy);
    if(windows2.rx < windows1.lx || windows1.rx < windows2.lx || windows2.dy < windows1.uy || windows1.dy < windows2.uy) printf("0\n");
    else {
        if((windows1.lx < windows2.lx) && (windows1.uy < windows2.uy)) printf("%d\n", (windows1.dy - windows2.uy) * (windows1.rx - windows2.lx));
        else if((windows2.lx < windows1.lx) && (windows2.uy < windows1.uy)) printf("%d\n", (windows2.dy - windows1.uy) * (windows2.rx - windows1.lx));
        else if((windows1.rx > windows2.rx) && (windows1.uy < windows2.uy)) printf("%d\n", (windows1.dy - windows2.uy) * (windows2.rx - windows1.lx));
        else if((windows2.uy < windows1.uy) && (windows2.rx > windows1.rx)) 
printf("%d\n", (windows2.dy - windows1.uy) * (windows1.rx - windows2.lx));
        else if(windows1.lx < windows2.lx && windows2.rx < windows1.rx && )
    }
    return 0;
 // 代码有错误，没考虑到左右边界处有包含关系。
}

