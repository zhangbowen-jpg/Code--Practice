/*************************************************************************
	> File Name: 72.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月07日 星期日 16时48分04秒
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
#define MAX_N 10000

struct UnionSet{
    int fa[MAX_N+5],val[MAX_N+5];
    void init(int n){
        for(int i = 1;i <= n; i++){
            fa[i] = i;      
    }
    }
        int get(int x){
            if(x == fa[x]) return x;
            int root = get(fa[x]);
            val[x] += val[fa[x]];
            val[x] %= 3;
            return fa[x] = root;
        }
        void merge(int a,int b, int t){
            int x = get(a),y = get(b);
            if(x == y) return ;
            fa[x] = y;
            val[x] = (val[b] + t - val[a] + 3) % 3;
            return ;
        }
};
UnionSet u;

int main() {
    int n,m;
        cin >> n >> m;
        u.init(n);
        for(int i = 0; i < m ;i++){
            int a, b, c;
            cin >> a >> b >> c;
            if (a == 1) {
            u.merge(b, c, 2);
        } else {
            if (u.get(b) != u.get(c)) {
                cout << "Unknown" << endl;
            } else {
                switch ((u.val[b] - u.val[c] + 3) % 3) {
                    case 0: cout << "Tie" << endl; break;
                    case 1: cout << "Loss" << endl; break;
                    case 2: cout << "Win" << endl; break;
                }
            }
        }
    }
    return 0;
}

