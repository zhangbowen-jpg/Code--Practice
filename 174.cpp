/*************************************************************************
	> File Name: 174.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月08日 星期四 12时38分51秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

char s[1000005] = {0};
char a[3000005] = {0};

int main() {
    gets(s);
    for(int i = 0, j = 0; s[i]; i++) {
        if(s[i] != ' ') {
            a[j] = s[i];
            j++;
        } else {
            a[j] = '%';
            a[j + 1] = '2';
            a[j + 2] = '0';
            j += 3;
        }
    }
    cout << a << endl;
    return 0;
}

