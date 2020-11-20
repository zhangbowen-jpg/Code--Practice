/*************************************************************************
	> File Name: 151.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月05日 星期一 19时34分50秒
 ************************************************************************/

#include<iostream>
using namespace std;

int check(char a, char b) {
    if (a == b) return 0;
    if (a == 'Y' && b == 'H' || a == 'O' && b == 'Y' || a == 'H' && b == 'O') {
    return 1;
    }
    return 2;
}

int main() {
    char ml, mr, ll, lr;
    cin >> ml >> mr >> ll >> lr;
    if(check(ml,ll) == 1) {
        if(check(ml, lr) != 2) {
            cout << "MING" << endl;
            return 0;
        }
        if (check(mr, lr) == 1) {
            cout << "MING" << endl;
            return 0;
        } else {
            cout << "LIHUA" << endl; 
            return 0;
        }
    } else if (check(ml, ll) == 0) {
        if (check(mr, lr) == 1) {
            cout << "MING" << endl;
            return 0;
        } else if (check(ml,lr) == 2) {
            cout << "LIHUA" << endl;
            return 0;
        } else {
            cout << "TIE" << endl;
            return 0;
        }
    } else {
        if(check(mr,ll) != 1) {
            cout << "LIHUA" <<endl;
            return 0;
        }
        if(check(mr,lr) != 2) {
            cout << "MING" << endl;
            return 0;
        } else {
            cout << "LIHUA" << endl;
            return 0;
        }
        
    }
    return 0;
}

