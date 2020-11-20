/*************************************************************************
	> File Name: cd.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年09月22日 星期日 19时23分58秒
 ************************************************************************/
#include<unistd.h>
#include<stdio.h>
#include<string.h>


#define SIZE 30
int cds(char *p)
{
    char path[SIZE];
    char *start;
    char *end;
    int res;

    memset(path,'\0',SIZE); 
    start = strchr(p,' ');
    end = strchr(p,'\n');
    strncpy(path,p+3,end-start-1);
    res = chdir(path); 
    return res;
}

int main(int argc,char *argv[]) {
    if(argc > 2) {
        printf("Invaild Argument");
        return 1;
    }
    char buf[SIZE];
    fgets(buf,SIZE,stdin);
    cds(buf);
    return 0;
}
