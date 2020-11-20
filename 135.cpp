/*************************************************************************
	> File Name: 135.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 14时17分33秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
using namespace std;
int day_month(int y,int m){
    switch (m) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10: 
        case 12: return 31;
        case 4: 
        case 6: 
        case 9:
        case 11: return 30;
    }
    if(y % 400 == 0|| y % 100 != 0 && y % 4 == 0)
        return 29;
    else {
        return 28;
    }
}

int main() {
    int x, y, m, d;
    cin >> x >> y >> m >> d;
    d += x;
    while (d > day_month(y, m)){
        d -= day_month(y, m); 
        m++;
        if (m == 13) {
            m = 1;
            y++;
        }
    }
    cout << y << " " << m << " " << d << endl;
    return 0;
}




