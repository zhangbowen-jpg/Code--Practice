/*************************************************************************
	> File Name: 120.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月21日 星期日 20时16分34秒
 ************************************************************************/
#include<stdio.h>
int main(){
    int year,month,day;
    scanf("%d%d%d",&year,&month,&day);
	if(year<0||month<=0||day<=0)printf("NO");
    if((year%4 != 0)||((year%4==0&&year%100==0)&&year%400!=0)){
        if(month<=12){
        if(month == 2){
            if(day<=28){
                printf("YES");
            }
            else{
                printf("NO");
            }
        }
        else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
            if(day<=31){
                printf("YES");
            }
            else{
                printf("NO");
            }
        }
        else if(month==4||month==6||month==9||month==11){
            if(day<=30){
                printf("YES");
            }
            else{
                printf("NO");
            }
        }
    }
        else{
            printf("NO");
        }
    }
    else{
         if(month<=12){
        if(month == 2){
            if(day<=29){
                printf("YES");
            }
            else{
                printf("NO");
            }
        }
        else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
            if(day<=31){
                printf("YES");
            }
            else{
                printf("NO");
            }
        }
        else if(month==4||month==6||month==9||month==11){
            if(day<=30){
                printf("YES");
            }
            else{
                printf("NO");
            }
        }
    }
        else{
            printf("NO");
        }
    }
    return 0;
}
