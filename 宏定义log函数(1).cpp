#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define COLOR(a, b)  "\033[" #b "m" a "\033[0m" 
#define RED(a)  COLOR(a, 31) 
#define BLUE(a)	 COLOR(a, 34)
#define GREEN(a)  COLOR(a, 32)
#define YELLOW(a)  COLOR(a, 33)

#ifndef DEBUG 

#define log(frm, args...) {\
	printf("\033[1;32m[%s : %d]\033[0m ", __func__, __LINE__);\
	printf(frm,##args);\
	printf("\n");\
}
//[后的1表示高亮，
//args... ->可变参数列表 //##表示连接内容，可以为空了  

#else
#define log(frm,args...)
#endif

#define __contact(a,b) a##b
#define contact(a,b) __contact(a,b) 
//再闭包一层，防止宏定义出bug 

/*#define ABS(x) _Generic((x),\
	int : abs(x),\
	double : fabs(x),\
	default : fabs(x)\
)
*/

int main() {
	int a = 7;
	int abcdef = 19;
	log(RED("%d"), a);
	log(GREEN("hello") " " RED("world")); //如果变参函数为空，程序会报错 
	log(BLUE("%d"), abcdef);
	contact(abc, def) = 21;
	//abcdef = 21
	log(YELLOW("%d"), abcdef);	
	//contact(contact(ab,c), contact(de,f)) = 23;
	return 0;
}
 
