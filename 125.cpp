/*************************************************************************
	> File Name: 125.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 20时54分13秒
 ************************************************************************/

#include<stdio.h>

int main() {
    int h,m,s,t;
    double num;
    scanf("%d%d%d%d",&h,&m,&s,&t);
    s = s+(t%60);
    if(s>=60){s=s%60;m=m+1;}
    m = m+((t%3600)/60);
    if(m>=60){m=m%60;h=h+1;}
    h = h+(t/3600);
    h = h%24;
    if(h<12){
        if(h==0){
        printf("12:%d:%dam\n",m,s);
        }
        else {printf("%d:%d:%dam\n",h,m,s);}
    }
    else {
        if(h==12)printf("12:%d:%dpm\n",m,s);
        else{
        printf("%d:%d:%dpm\n",h-12,m,s);
        }
        }
    num = (double)t/864;
    printf("%.2f%%",num);
}

