/*************************************************************************
	> File Name: Vector2.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月03日 星期四 19时09分59秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Vector {
	int size,length;
    int *data;
} Vector;

void init(Vector *vector,int size) {
	vector->size = size;
    vector->length = 0;
    vector->data = (int *)malloc(sizeof(int) * size);
}

void expand(Vector *vector) {
    vector->size *= 2;
	vector->data = (int *)realloc(vector->data, vector->size * sizeof(int));;
    printf("expand\n");
}

int insert(Vector *vector, int loc, int value) {
	if (loc < 0 || loc > vector->length) {
        return ERROR;
    }
    if (vector->length >= vector->size) {
        expand(vector);
    }
    for (int i = vector->length; i > loc; --i) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[loc] = value;
    ++vector->length;
    return OK;
}


void clear(Vector *vector) {
	free(vector->data);
    free(vector);
}

int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    init(a, 5);
    int n,p,q;
	scanf("%d",&n);
    for(int i = 1; i <= n; i++) {
    	scanf("%d%d", &p,&q);
        printf("%s\n",insert(a,p,q) == OK ? "success" : "failed");   
    }
    clear(a);
    return 0;
}
