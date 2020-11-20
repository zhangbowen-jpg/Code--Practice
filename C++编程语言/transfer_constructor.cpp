/*************************************************************************
	> File Name: transfer_constructor.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月10日 星期二 18时27分29秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;

class BigInt {
public:
    BigInt() {}
    BigInt(int x) {
        num.push_back(x);
        proccess_digit();
    }
private:
    vector<int> num;
    void proccess_digit() {
        for(int i = 0; i < num.size(); i++) {
            if(num[i] < 10) continue;
            if(i + 1 == num.size()) num.push_back(0);
            num[i + 1] = num[i] / 10;
            num[i] %= 10;
        }
        return ;
    }
};

ostream &operator<<(ostream &out, const BigInt &a) {
    for(int i = a.num.size() - 1; i >= 0; i++) {
        out << a.num[i];
    }
    return out;
}

void func(BigInt a) {
    cout << "func : " << a << endl;
}

int main() {
    BigInt a;
    a = 1234;
    cout << a << endl;
    func(5670);
    return 0;
}



