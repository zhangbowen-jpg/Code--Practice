/*************************************************************************
	> File Name: pc.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年08月31日 星期一 14时02分53秒
 ************************************************************************/
#include <iostream>
using namespace std;
int fun (int x,int y)
{
    if(x==y)
        return (x);
    else 
        return ((x+y)/2);
}
int main()
{  
    int a=4,b=5,c=6;
    printf("%d\n",fun(2*a,fun(b,c)));
}
