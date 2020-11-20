/*************************************************************************
	> File Name: 1.vector.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月02日 星期三 15时14分41秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

typedef struct Vector {
    int size, length;
    int *data;
}Vector;

Vector *init(int size) {
    Vector *vector = (Vector *)malloc(sizeof(Vector));
    vector->data = (int *)malloc(sizeof(int) * size); //开辟一片连续存储空间，并返回首地址
    vector->size = size;
    vector->length = 0;
    return vector;
}

int expand(Vector *vector) {
/*    vector->size *= 2;
      vector->data = (int *)realloc(vector->data, sizeof(int) * vector->size);
    //calloc是开辟并赋值 ，realloc重新分配内存，并将原来的内容复制进去。但是一旦空间不够realloc失败会返回空地址，所有数据都会消失。。
*/
    int extr_size = vector->size;
    int *p;
    while(extr_size) {
        p = (int *)realloc(vector->data, sizeof(int) * (vector->size + extr_size)); //int * 是必要的
        if(p) break;
        extr_size /= 2;
    }
    if(p == NULL) return 0;
    vector->size += extr_size;
    vector->data = p;
    return 1;
}

int insert(Vector *vector, int ind, int val) {
    if(vector == NULL) return 0;
    if(ind < 0 || ind > vector->length) return 0;
    if(vector->size == vector->length){
        if(!expand(vector)) return 0;
        printf("expand Vector success = (%d)\n", vector->size);
    }
    for(int i = vector->length; i > ind; i--) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[ind] = val;
    vector->length += 1;
    return 1;
}

int erase(Vector *vector, int ind) {
    if(vector == NULL) return 0;
    if(ind < 0 || ind >= vector->length) return 0;
    for (int i = ind + 1; i < vector->length; i++) {
        vector->data[i - 1] = vector->data[i];
    }
    vector->length -= 1;
    return 1;
}
//删除某个位值的值 ind = vector->length 是因为length位值是空的

void output(Vector *vector) {
    printf("Vector(%d) = [", vector->length);
    for(int i = 0; i < vector->length; i++) {
        i && printf(", ");
        printf("%d", vector->data[i]);
    }
    printf("]\n");
}

void clear(Vector *vector) {
    if(vector == NULL) return ;
    free(vector->data);
    free(vector);
    return ;
}
//需要先释放data ，在释放顺序表，否则会造成内存泄露
int main() {
    srand(time(0));
    Vector *vector = init(1);
    #define max_op 20
    int op, ind, val;
    for(int i = 0; i < max_op; i++) {
        op = rand() % 4; 
        ind = rand() % (vector->length + 3) - 1;//在正确数据中添加错误用例。
        val = rand() % 100; //随机化生成
        switch (op) {
            case 2 :
            case 3 :
            case 0 : {
                printf("insert %d at %d to Vector = %d\n", val, ind, insert(vector, ind, val));
                output(vector);
                printf("\n");
            } break;
            //插入概率75% 删除概率25%
            case 1 : {
                printf("erase element at %d from Vector = %d\n", ind, erase(vector,ind));
                output(vector);
                printf("\n");
            } break;
        }
    }
    clear(vector);
    return 0;
}

