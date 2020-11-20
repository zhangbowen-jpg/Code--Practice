/*************************************************************************
	> File Name: 440.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年07月15日 星期三 19时44分36秒
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

int main() {
    int n, x;
    int arrx[10] = {0};
    cin >> n >> x;
    
    for(int i = 1; i <= n; i++) {
        int a = i;
        while(a != 0) {
            switch (a % 10) {
                case 0: arrx[0]++; break;
                case 1: arrx[1]++; break;
                case 2: arrx[2]++; break;
                case 3: arrx[3]++; break;
                case 4: arrx[4]++; break;
                case 5: arrx[5]++; break;
                case 6: arrx[6]++; break;
                case 7: arrx[7]++; break;
                case 8: arrx[8]++; break;
                case 9: arrx[9]++; break;
            }
            a /= 10;
        }
    #include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;

int main() {
    int n, x;
    int arrx[10] = {0};
    cin >> n >> x;
    
    for(int i = 1; i <= n; i++) {
        int a = i;
        while(a != 0) {
            switch (a % 10) {
                case 0: arrx[0]++; break;
                case 1: arrx[1]++; break;
                case 2: arrx[2]++; break;
                case 3: arrx[3]++; break;
                case 4: arrx[4]++; break;
                case 5: arrx[5]++; break;
                case 6: arrx[6]++; break;
                case 7: arrx[7]++; break;
                case 8: arrx[8]++; break;
                case 9: arrx[9]++; break;
            }
            a /= 10;
        }
    }
    cout << arrx[x] << endl;

    return 0;
}

}
    cout << arrx[x] << endl;

    return 0;
}


