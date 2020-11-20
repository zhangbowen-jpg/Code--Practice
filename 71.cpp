/*************************************************************************
	> File Name: 71.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月07日 星期日 16时07分54秒
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
    //   int fa[MAX_N+5];
    int fa[MAX_N+5];//size[MAX_N+5]//按质优化;
    void init(int n){
        for(int i = 1;i<=n;i++){
            fa[i]=i;
        // size[i]=1;
        }
    }
    int get(int x){
        return(fa[x]=(x==fa[x]?x:get(fa[x])));
void merge(int a, int b){
          fa[get(a)]= get(b);
//        int aa = get(a),bb=get(b);
//        if(aa = bb) return ；
//        if(size[aa]<size[bb]) swap(aa,bb);
//            fa[aa]=get(bb);
///       if(size[aa]>size[bb]){
///           fa[bb]=aa;
///            size[aa]+=size[bb];
///        }
///        else
///        {
///            fa[aa]=bb;
///            size[aa]+=size[aa];
//        }
//       return ;
//       fa[get(a)]=get(b); 
    }
};
UnionSet u;
int main(){
    int n,m;
    cin>>n>>m;
    u.init(n);
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        switch(a){
            case 1:{
                u.merge(b,c);
            }break;
            case 2:{
                cout<<(u.get(b)==u.get(c)?"Yes":"No")<<endl;
            }break;
        }
    }
    return 0;
}
