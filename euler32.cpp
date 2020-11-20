/*************************************************************************
	> File Name: euler32.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月09日 星期五 15时44分48秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define max_n 10000

inline int add_to_num(int x, int *num) {
    while (x) {
        if (num[x % 10]) return 0;//如果有重复的数字就返回0，仔细看判断条件
        num[x % 10] += 1;//该位为0就赋值1
        x /= 10;
    }
    return 1;
}  

inline int digits(int x) { // 计算总共的位数
    return floor(log10(x)) + 1;
}

int is_vaild(int a, int b, int c) {
    if(digits(a) + digits(b) + digits(c) != 9) return 0;//判断是否是九位
    int num[10] = {0};
    num[0] = 1;
    int flag = 1;
    flag = flag && add_to_num(a, num);
    flag = flag && add_to_num(b, num); //如果前面出现假则不会执行后面的语句
    flag = flag && add_to_num(c, num);
    return flag;    
}
   
int keep[max_n + 5] = {0};

int main() {
    int sum = 0;
    for (int  a = 1; a < 100; a++) {
        for (int b = a + 1; b < 10000; b++) {
            if (!is_vaild(a, b, a * b)) continue;
            if (keep[a * b]) continue; // 确保乘积只出现一次。
            sum += a * b;
            keep[a * b] = 1;
        }
    }
    printf("%d\n", sum);
    return 0;
}

