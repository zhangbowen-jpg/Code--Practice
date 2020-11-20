/*************************************************************************
	> File Name: 7.23.7.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月23日 星期二 20时08分01秒
 ************************************************************************/

#include<stdio,h>
#include<math.h>
#include<inttypes.h>
int main(){
///    int16_t a;
///    printf("%s\n",PRId8);
///    printf("%s\n",PRId16);
///    printf("%s\n",PRId32);
///    printf("%s\n",PRId64);
///    return 0;
//    int a=123;
//    printf("%s\n",PRId8);
//    printf("%s\n",PRId16);
//    printf("%s\n",PRId32);
//    printf("%s\n",PRId64);
//    printf("%s\n",PRIo8);
//    printf("%s\n",PRIo16);
//    printf("%s\n",PRIo32);
//    printf("%s\n",PRIo64);
//    printf("%s\n",PRIx8);
//    printf("%s\n",PRIx16);
//    printf("%s\n",PRIx32);
//    printf("%s\n",PRIx64);
    int64_t a=123;
    printf("%" PRId64 "\n",a);
    printf("%" PRId8 "%" PRId8 "\n",INT8_MIN,INT8_MAX);
    printf("%" PRId16 "%" PRId16 "\n",INT16_MIN,INT16_MAX);
    printf("%" PRId32 "%" PRId32 "\n",INT32_MIN,INT32_MAX);
    printf("%" PRId64 "%" PRId64 "\n",INT64_MIN,INT64_MAX);
    return 0;
}



