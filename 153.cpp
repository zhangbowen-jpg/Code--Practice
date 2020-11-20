/*************************************************************************
	> File Name: 153.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月30日 星期二 15时57分33秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int year, month, day;
    scanf("%d%d%d", &year, &month, &day);
    if (month <= 2) {
        month += 12;
        y--;
    }
    int h = (d + 26 * (m + 1) / 10 + y % 100 + y % 100 / 4 + y / 100 / 4 + 5 * (y / 100)) % 7;
    switch (h) {
        case 0 : printf("6");
        case 1 : printf("7");
        case 2 : printf("1");
        case 3 : printf("2");
        case 4 : printf("3");
        case 5 : printf("4");
        case 6 : printf("5");
    }
    return 0;
}

