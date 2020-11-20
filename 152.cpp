/*************************************************************************
	> File Name: 152.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月27日 星期六 17时54分48秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    switch ((n+3)%7) {
        case 0: printf("Sunday"); break;
        case 1: printf("Monday"); break;
        case 2: printf("Tuesday"); break;
        case 3: printf("Wednesday"); break;
        case 4: printf("Thursday"); break;
        case 5: printf("Friday"); break;
        case 6: printf("Saturday");
    }
    return 0;
}

