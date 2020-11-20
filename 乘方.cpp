#include <iostream>
#include <stdio.h>
#include <string.h>
#define max_n 100
using namespace std;

int rst[max_n + 5] = {0};

void print(int *rst) {
    for (int i = rst[0]; i >= 1; i--) {
        cout << rst[i];
        if (i == 1) cout << endl;
    }
}

void mul(int a, int b, int *rst) {
    memset(rst, 0, sizeof(rst));
    rst[0] = 1;
    rst[1] = 1;
    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= rst[0]; j++) {
            rst[j] *= a;
        }
        for (int j = 1; j <= rst[0]; j++) {
            if (rst[j] < 10) continue;
            rst[j+1] += rst[j]/10;
            rst[j] %= 10;
            if (j == rst[0] && rst[rst[0]+1] > 0) rst[0]++;
        }
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    mul(a, b, rst);
    print(rst);

    return 0;
}

