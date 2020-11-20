/*************************************************************************
	> File Name: 7.23.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月23日 星期二 15时36分49秒
 ************************************************************************/
#include<stdio.h>

int main(){
    int ret;
    char str[100];
    while (ret = (scanf("%[^\n]s", str)) != EOF){//[^\n]，\n字符停止读入
    getchar();//用于将\n字符取出
//  printf("%s %d\n",str,ret);
    printf(" has %d chars\n", printf("%s",str));
//  等价于  n=printf("%s",str); printf(" has %d chars",n);
    }
}

