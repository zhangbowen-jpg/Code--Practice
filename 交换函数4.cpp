/*************************************************************************
	> File Name: 交换函数4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月02日 星期五 16时51分48秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define swap(a, b) {\
    __typeof(a) temp = a;\
    a = b; b = temp;\
}
//宏必须按一行进行写和编译，其中的\用来将这行与下一行进行连接 其速度远快于函数，直接在存储空间内部进行调用。

int main() {
    int a,b;
    cin >> a >> b;
    swap(a,b);
    cout << a << " " << b << endl;
    return 0;

}

