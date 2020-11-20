/*************************************************************************
	> File Name: 交换函数3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月02日 星期五 16时39分15秒
 ************************************************************************/

#include<iostream>
using namespace std;

void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
    return ;
}

int main() {
    int a,b;
    cin >> a >> b;
    swap(a, b);
    cout << a << " " << b << endl;
    return 0;

}

