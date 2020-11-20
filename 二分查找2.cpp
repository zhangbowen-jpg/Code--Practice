/*************************************************************************
	> File Name: 二分查找2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月08日 星期一 15时29分33秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int Triangle(int n){
    return n*(1+n)/2;
}
//三角形数公式
int pentagon(int n){
    return n*(3*n-1)/2;
}
//五边形数公式
int binary_search3(int (*func)(int),int n,int x){
    int head = 0,tail =n,mid;
    while(head<=tail){
    mid = (head+tail)>>1;
    if(func(mid)==x) return mid;
    if(func(mid)>x)tail=mid-1;
    else head=mid+1;
    }
    return -1;
}

int binary_search1(int *arr, int n, int x, int &t) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        t += 1;
        mid = (head + tail) >> 1;
        if (arr[mid] == x) return mid;
        if (arr[mid] > x) tail = mid - 1;
        else head = mid + 1;
    }
    return -1;
}

int binary_search2(int *arr, int l, int r, int x, int &t) {
    t += 1;
    if (l > r) return -1;
    int mid = (l + r) >> 1;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) r = mid - 1;
    else l = mid + 1;
    return binary_search2(arr, l, r, x, t);
}

#define MAX_N 15
int arr[MAX_N + 5];

int main() {
    srand(time(0));
    arr[0] = rand() % 10;
    for (int i = 1; i < MAX_N; i++) {
        arr[i] = arr[i - 1] + rand() % 10;
    }
    for (int i = 0; i < MAX_N; i++) {
        printf("%3d", i);
    }
    printf("\n");
    for (int i = 0; i < MAX_N; i++) {
        printf("%3d", arr[i]);
    }
    printf("\n");
    int x;
    while (~scanf("%d", &x)) {
        int t1 = 0, t2 = 0;
        printf("binary_search1(%d) = %d\n", 
               x, binary_search1(arr, MAX_N, x, t1));
        printf("binary_search2(%d) = %d\n", 
               x, binary_search2(arr, 0, MAX_N - 1, x, t2));
        printf("binary_search3(%d) = %d\n",x,binary_search3(Triangle,x,x));
        printf("binary_search3(%d) = %d\n",x,binary_search3(pentagon,x,x));
        printf("binary_search1(times) = %d\n", t1);
        printf("binary_search2(times) = %d\n", t2);
    }
    return 0;
}

