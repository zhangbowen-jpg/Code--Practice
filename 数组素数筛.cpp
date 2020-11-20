#include<stdio.h>
#define MAX_N 1000
/* int prime[MAX_N + 5];
 
void init_prime() {
	prime[0] = prime[1] = 1;
	for(int i = 2; i * i <= MAX_N; j += i) {
		if(prime[i]) continue;
		for(int j = i * i; j <= MAX_N; j += i) {
			prime[j] = 1;
		}
	}
	return ;
}
*/
int prime(int x) {
	if(x <= 1) return 1;
	for(int i = 2; i * i <= x; i++) {
	if(x % i) continue;
	return 1;
	}
	return 0;
}
int main() {
	int x;
	while(~scanf("%d", &x)) {
		printf("%s\n", prime(x) ? "NO" : "Yes");
	}
	return 0;
}

 
