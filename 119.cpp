/*************************************************************************
	> File Name: 119.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月21日 星期日 19时16分17秒
 ************************************************************************/
#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(b==1&&c==1){
    printf("%d 12 31\n",a-1);
    printf("%d %d %d",a,b,c+1);
    }
    else if(b==12&&c==31){
    printf("%d %d %d\n",a,b,c-1);
    printf("%d 1 1",a+1);
    }
    else if((a%400==0||(a%4==0&&a%100!=0))&&b==2){
     if(c==1){
     printf("%d 1 31\n",a);
     printf("%d 2 2",a);
     }
     else if(c==29){
     printf("%d 2 28\n",a);
     printf("%d 3 1",a);
     }
     else{
     printf("%d %d %d\n",a,b,c-1);
     printf("%d %d %d",a,b,c+1);
     }
    }
    else if(((a%400!=0&&(a%4==0&&a%100==0))||a%4!=0)&&b==2){
     if(c==1){
     printf("%d 1 31\n",a);
     printf("%d 2 2",a);
     }
     else if(c==28){
     printf("%d 2 27\n",a);
     printf("%d 3 1",a);
     }
     else{
     printf("%d %d %d\n",a,b,c-1);
     printf("%d %d %d",a,b,c+1);
     }
    }
    else if((a%400!=0&&a%4!=0&&(a%4==0&&a%100==0)&&b==3)){
    if(c==1){
    printf("%d 2 28\n",a);
    printf("%d 3 2",a);
    }
    else if(c==31){
    printf("%d 3 30\n",a);
    printf("%d 4 1",a);
    }
    else{
    printf("%d %d %d\n",a,b,c-1);
    printf("%d %d %d",a,b,c+1);
    }
    }
    else if(((a%400==0)||(a%4==0&&a%100!=0))&&b==3){
    if(c==1){
    printf("%d 2 29\n",a);
    printf("%d 3 2",a);
    }
    else if(c==31){
    printf("%d 3 30\n",a);
    printf("%d 4 1",a);
    }
    else{
    printf("%d %d %d\n",a,b,c-1);
    printf("%d %d %d",a,b,c+1);
    }
    }
    else if(b==1||b==5||b==7||b==8||b==10||b==12){
    if(c==1){
    printf("%d %d 30\n",a,b-1);
    printf("%d %d 2",a,b);
    }
    else if(c==31){
    printf("%d %d 30\n",a,b);
    printf("%d %d 1",a,b+1);
    }
    else{
    printf("%d %d %d\n",a,b,c-1);
    printf("%d %d %d",a,b,c+1);
    }
    }
    else{
    if(c==1){
    printf("%d %d 31\n",a,b-1);
    printf("%d %d 2",a,b);
    }
    else if(c==30){
    printf("%d %d 29\n",a,b);
    printf("%d %d 1",a,b+1);
    }
    else{
    printf("%d %d %d\n",a,b,c-1);
    printf("%d %d %d",a,b,c+1);
    }    
    }
    return 0;
    }
    
