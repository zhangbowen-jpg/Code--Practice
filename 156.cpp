/*************************************************************************
	> File Name: 156.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月27日 星期六 18时14分42秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int isVaild(int x) {
    for(int i = 2; i < x; i++) {
        if(x%i==0) return false;
    }
    return true;
}
int qbisTwice(int x) {
    int q,w,num;
    q = x/1000;
    w = (x%1000)/100;
    num = q*10+w;
    double c=sqrt(num);
    if(c==int(c)) return true;
    else return false;
}
int gsisTwice(int x) {
    int q,w,num;
    q = (x%100)/10;
    w = x%10;
    num = q*10+w;
    double c=sqrt(num);
    if(c==int(c)) return true;
    else return false;
}

int main() {
    int a,b,n = 0,flag = 0;
    scanf("%d%d", &a, &b);
    for(int i = a; i <= b; i++) {
        if(isVaild(i) && qbisTwice(i) && gsisTwice(i)) {
            if(flag == 1){
            printf(" ");
            }
            printf("%d",i);
            n += 1;
            flag = 1;
        }
    }
    printf("\n");
    printf("%d",n);

    return 0;
}

