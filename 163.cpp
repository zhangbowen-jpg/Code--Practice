/*************************************************************************
	> File Name: 163.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月05日 星期一 13时42分53秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int main() {
    double a,b,c,f;
    scanf("%lf%lf%lf",&a,&b,&c);
    f = sqrt(a * a + b * b - 2 * a * b * cos((c / 180) * acos(-1)));
    printf("%.6f",f);
    return 0;
}

