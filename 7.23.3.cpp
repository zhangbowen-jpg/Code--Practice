/*************************************************************************
	> File Name: 7.23.3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月23日 星期二 16时54分44秒
 ************************************************************************/

#include<stdio.h>
#define swap(a,b){\
    __typeof(a) temp=a;\
    a=b,b=temp\
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%04d",n);
//  printf("EOF=%d stdin=%d stdout=%d stderr=%d",EOF,stdin,stdout,stderr);
    char str[100];
    sprintf(str,"%d.%d.%d.%d",192,168,1,10);//写入字符串
    printf("str=%s\n",str);
    if(n&1){
      sprintf(q,"(%s)",p);
      swap(p,q);
    }
    if(n&2){
      sprintf(str,"[%s]",str);
      swap(p,q);
    }
    if(n&4){
      sprintf(str,"{%s}",str);
      swap(p,q);
    }
    FILE *fout = fopen("output", "w");
    fprintf(stdout, "stdout = %s\n", p);//写入文件
    fprintf(stderr, "stderr = %s\n", p);
    return 0;
}
