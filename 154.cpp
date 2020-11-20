/*************************************************************************
	> File Name: 154.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月27日 星期六 15时58分43秒
 ************************************************************************/

#include <stdio.h>
int main() {
	int n,flag;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        flag = 0;
        for(int j = i; j <= n; j++) {
            if(flag == 1) printf(" ");
            printf("%d",n-j+1);
            flag = 1;
    	}
	printf("\n");
	}
    return 0;
}
