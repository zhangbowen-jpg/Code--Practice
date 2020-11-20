/*************************************************************************
	> File Name: 7.27.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月27日 星期六 18时53分15秒
 ************************************************************************/

#include <stdio.h>
int factorial(int n){
 	if(n == 1) return 1;
    return factorial(n-1)*n;
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%d",factorial(n));
    return 0;
}

