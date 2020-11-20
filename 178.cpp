/*************************************************************************
	> File Name: 178.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月08日 星期四 11时15分39秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

char str[5000000] = {'A'};

int l;

int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1; i < n; i++) {
        l = strlen(str);
        for(int j = 0; j < l; j++) {
            str[2 * l - j] = str[j];
        }
        str[l] = 'A' + i;
    }
    for(int i = 0; i <=2 * l; i++) {
        printf("%c",str[i]);    
    }
    return 0;
}

