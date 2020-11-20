/*************************************************************************
	> File Name: leetcode202.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月04日 星期五 18时12分00秒
 ************************************************************************/
int next(int x) {
    int ans = 0;
    while(x != 0) {
        ans = ans + (x % 10) * (x % 10);
        x /= 10;
    }    
    return ans;
}

bool isHappy(int n){
    int p = n, q = n;
    do {
        q = next(q);
        p = next(next(p));
    } while(p != q && p != 1);
    return p == 1;
}

