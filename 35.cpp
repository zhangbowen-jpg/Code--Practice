/*************************************************************************
	> File Name: 35.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月22日 星期四 22时04分35秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    long long kaishi,jieshu;
    cin >> kaishi >> jieshu;
    if(kaishi < 0) kaishi = 0;
    if(jieshu < kaishi) printf("ERROR");
    for(long long i = kaishi; i <= jieshu; i++) {
        cout << i << endl;
    }
    return 0;
}

