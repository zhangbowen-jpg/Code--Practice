/*************************************************************************
	> File Name: 交换函数2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月02日 星期五 16时36分44秒
 ************************************************************************/

#include<iostream>
using namespace std;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return ;
}
//直接传地址，当指针使:

int main() {
    int a,b;
    cin >> a >> b;
    swap(&a, &b);
    cout << a << " " << b << endl;
    return 0;

}

