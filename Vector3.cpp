/*************************************************************************
	> File Name: Vector3.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月03日 星期四 19时10分24秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Vector {
	int size, length;
    int *data;
} Vector;

void init(Vector *vector, int size) {
	vector->size = size;
    vector->length = 0;
    vector->data = (int *)malloc(sizeof(int)*size);
}

void expand(Vector *vector) {
	int *old_data = vector->data;
    vector->size = vector->size * 2;
    vector->data = (int *)malloc(sizeof(int) * vector->size);
    for(int i = 0; i < vector->length; ++i) {
        vector->data[i] = old_data[i];
    }
    free(old_data);
}

int insert(Vector *vector, int loc, int value) {
	if(loc < 0 || loc > vector->length) {
        return ERROR;
    }
    if(vector->length >= vector->size) {
    	expand(vector);
    }
    for(int i = vector->length; i > loc; --i) {
        vector->data[i] = vector->data[i - 1];
    } 
    vector->data[loc] = value;
    vector->length++;
    return OK;
}

int search(Vector *vector, int value) {
	for (int i = 0; i < vector->length; ++i) {
        if (vector->data[i] == value) {
            return i;
        }
    }
    return -1;
}

int delete_node(Vector *vector, int index) {
	if(index < 0 || index >= vector->length) {
        return ERROR;
    }
    for(int i = index + 1; i < vector->length; i++) {
   			vector->data[i - 1] = vector->data[i];      
    }
    vector->length--;
    return OK;
}

void print(Vector *vector) {
	for(int i = 0; i < vector->length; i++) {
        if(i > 0) {
            printf(" ");//？？？
        }
        printf("%d",vector->data[i]);
    }
    printf("\n");
}

void clear(Vector *vector) {
	free(vector->data);
    free(vector);
}

int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    init(a, 20);
    int x, y, b, c, m, n;
	scanf("%d", &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d", &n);
        switch(n) {
            case 1 : 
                scanf("%d%d",&x,&y);
                printf("%s\n", (insert(a, x, y) == OK ? "success" : "failed"));
                break;
            case 2 : 
                scanf("%d",&b);
                printf("%s\n", (delete_node(a, b) == OK ? "success" : "failed"));
                break;
            case 3 : 
                scanf("%d",&c);
                printf("%s\n", (search(a, c) != -1 ? "success" : "failed"));
                break;
            case 4 : 
                print(a);
                break;
            default : 
                printf("ERROR\n");
        }
    }
    return 0;
}
