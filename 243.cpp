/************************************************************************
	> File Name: 243.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月08日 星期一 16时22分39秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

//二分加判定 找第一个一 前缀和数组
#define MAX_N 200000
struct Range{
    long long l,r,d;
    long long cnt;
}arr[MAX_N+5];
long long check(long long pos, int n){
    long long sum =0;
    for(int i = 0; i < n; i++){
        if(arr[i].l > pos) continue;
        if(arr[i].r <= pos) sum += arr[i].cnt;
        else sum += (pos-arr[i].l)/arr[i],d+1;
    }
    return sum;
}

long long binary_search(long long l,long long r,int n){
    if(l == r)return l;
    long long mid = (l+r) >> 1;
    if(check(mid,n) % 2) r = mid;
    else l = mid+1;
    return binary_search(l,r,n);
}
int solve(){
    int n
    long long l,r;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%lld%lld%lld",arr[i]->l,arr[i]->r,arr[i]->d);
        arr[i].cnt = (arr[i].r - arr[i].l) / arr[i].d + 1;
        if(i == 0) l = arr[i].l,r = arr[i].r;
        l = min(l,arr[i].l);
        r = max(r,arr[i].r);
    }
    int pos = binary_search(l,r+1,n);
    if(pos > r){
        cout << "Poor QIN Teng:()" << endl;
    }
    else{
        printf("%lld %lld\n", pos, check(pos, n) - check(pos, n - 1));
    }
}


int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
