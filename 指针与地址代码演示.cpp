#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define offset(T, a) (long long)(&(((T *)(NULL))->a))
// 将/0转换成T *类型的地址
#define pchar char * //这个不过是替换
typedef char * ppchar;  //这个是真正定义的类型

struct Data {
    int a;
    double b;
    char c;
};

void output_args(int argc, char *argv[], char *env[]) {
    for(int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    for(int i = 0; env[i]; i++) {
        printf("env[%d] = %s\n", i, env[i]);//打印环境变量
        if(strncmp(env[i], "USER=", 5) == 0) {//只有在某个用户才能执行
            if(strcmp(env[i] + 5, "zhangbowen")) {
                printf("you are not zhangbowen, don't run me! GUN!");
                exit(0);
            }
        }
    }
    return ;
}

int main(int argc, char *argv[], char *env[]) {//第一个参数表达参数个数，第二个表示参数数组，如果想传带空格的字符，需要在两边加“”,第三个（及后面）参数表示环境参数。
	int num1 = 0x616263; //十六进制 61转化为十进制97 二进制代表a
	int num2 = 0x61626364; 
	printf("%s\n", (char *)(&num2));  
    offset(Data, a); //宏定义 输出Data结构体中a字段的偏移量
    printf("%lld\n",offset(struct Data, a));
    printf("%lld\n",offset(struct Data, b));
    printf("%lld\n",offset(struct Data, c));
    pchar p1, p2;
    ppchar p3, p4;
    //char *指针占8个字节
    printf("sizeof(p1) = %lu sizeof(p2) = %lu\n",sizeof(p1),sizeof(p2));
    printf("sizeof(p3) = %lu sizeof(p4) = %lu\n",sizeof(p3),sizeof(p4));
    output_args(argc, argv, env);
	return 0;
}

