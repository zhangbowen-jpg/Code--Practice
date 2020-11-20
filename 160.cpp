/*************************************************************************
	> File Name: 160.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月29日 星期一 15时09分23秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define PI 3.14
int main() {
    double r,h,S,L;    
    scanf("%lf%lf", &r, &h);
    double sum;
    S = PI*r;
    L = sqrt(r*r*8);
    sum = S * h + (PI*r*r/2 + 2*r*r)*2 + L * h + 2 * r * h;
    printf("%.2f",sum);
    return 0;
}

