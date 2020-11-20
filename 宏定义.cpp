#include<stdio.h>
#define MAX(a,b) {\
	__typeof(a) _a = (a);\
	__typeof(b) _b = (b);\
	_a > _b ? _a : _b;\
}
#ifdef DEBUG //如果存在DEBUG这个宏，则替换P(a) 
#define P(a) {\
	printf("[%s : %d] %s = %d\n", __func__, __LINE__, #a, a);\
}
#else //否则P(a),为空 
#define P(a)
#endif

int main() {
	int a = 7;
	printf("%d\n",MAX(2,3));
	printf("%d\n",5 + MAX(2,3));
	printf("%d\n",MAX(2,MAX(3,4)));
	printf("%d\n",MAX(2, 3 > 4 ? 3 : 4));
	printf("%d\n",MAX(a++, 6));
	printf("%d\n",a);
	P(MAX(2,3));
	P(5 + MAX(2,3));
	P(MAX(2,MAX(3,4)));
	P(MAX(2,3 > 4 ? 3 : 4));
	P(MAX(a++, 6));
	P(a);
	return 0;
}

