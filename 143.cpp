/*************************************************************************
	> File Name: 143.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月26日 星期五 00时32分02秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int isvaild(int n) {
    int z,x,num;
    z = n/1000;
    x = (n%1000)/100;
    num = z*10+x;
    for(int i = 2; i < num; i++) {
        if(num%i==0) return false;
    }
    return true;
}
int isPF(int n) {
    int q,w,num;
    q = (n%100)/10;
    w = n%10;
    num = q*10+w;
    double c=sqrt(num);
    if(c==int(c)) return true;
    else return false;
}



int main() {
    int a,b,flag=0,n=0;
    scanf("%d%d",&a,&b);
    for(int i = a; i <= b; i++) {
        if(isvaild(i)&&isPF(i)){
            if(i%6==0) {
                if(flag==1){
                printf(" ");
                }
                printf("%d",i);
                flag = 1;
                n++;
            } else continue;
        } else continue;
    }
    printf("\n");
    printf("%d",n);
    return 0;
}

