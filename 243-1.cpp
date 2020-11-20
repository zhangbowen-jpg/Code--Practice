/*************************************************************************
	> File Name: 243-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月21日 星期三 18时17分25秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;
#define max_n 200000

long long arr[max_n + 5][4];

long long check(long long a, int n){
    long long sum = 0;
    for(int i = 0; i < n; i++){
        if(arr[i][0] > a)continue;
        if(arr[i][1] <= a) sum += arr[i][3];
        else sum += (a - arr[i][0]) / arr[i][2] + 1;
    }
    return sum;
}

long long binary_search(long long l,long long r,int n){
    if(l == r) return l;
    long long mid = (l + r) >> 1;
    if(check(mid, n) % 2) r = mid;
    else l = mid + 1;
    return binary_search(l,r,n);
}

void solve() {
    int n;
    long long l,r;
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%lld%lld%lld",&arr[i][0],&arr[i][1],&arr[i][2]);
        arr[i][3] = (arr[i][1] - arr[i][0]) / arr[i][2] + 1;
        if(i == 0) l = arr[i][0]; r = arr[i][1];
        l = min(arr[i][0],l);
        r = max(arr[i][1],r);
    }
    long long ans = binary_search(l, r + 1, n);
    if(ans > r) {
        cout << "Poor QIN Teng:(\n";
    } else {
        cout << ans << " " << check(ans,n) - check(ans - 1, n) << endl;
    }
    return ;
}

int main() {
    int n;
    cin >> n;
    while(n--) solve();
    return 0;
}

