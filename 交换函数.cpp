/*************************************************************************
	> File Name: 交换函数.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月02日 星期五 16时32分14秒
 ************************************************************************/

#include<iostream>
using namespace std;

//注意参数前的取址符（引用），直接传值
void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
    return ;
}

int main() {
    int a,b;
    cin >> a >> b;
    swap(a, b);
    cout << a << " " << b << endl;
    return 0;

}

