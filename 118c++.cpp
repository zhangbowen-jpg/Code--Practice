/*************************************************************************
	> File Name: 118c++.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月28日 星期日 12时37分51秒
 ************************************************************************/

#include<iostream>
using namespace std;

char str[][10] = {
    "rat","ox","tiger","rabbit","dragon","snake","horse","sheep","monkey","rooster","dog","pig"
};

int main() {
    int y;
    cin >> y;
    cout << str[(((y - 1900) % 12 +12) % 12)] << endl;
    return 0;
}
