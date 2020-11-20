/*************************************************************************
	> File Name: 4.Stack.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月05日 星期六 18时10分40秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Stack {
    int *data;
    int top, size;
}Stack;

Stack *init(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->size = n;
    s->top = -1; //初始栈顶指针为-1
}

int empty(Stack *s) {
    return s->top == -1;
}

int top(Stack *s) {
    if(empty(s)) return 0;
    return s->data[s->top];
}

int expand(Stack *s) {
    int old_stack = s->size;
    int *p;
    while(old_stack) {
        p = (int *)realloc(s->data, sizeof(int) * (old_stack + s->size));
        if(p) break;
        old_stack /= 2;
    }
    s->data = p;
    s->size += old_stack;
    if(!p) return 0;
    return 1;
}

int push(Stack *s, int val) {
    if(s == NULL) return 0;
    if(s->top + 1 >= s->size) {// 栈和队列都是从0开始记录
        if(!expand(s)) return 0;
        printf("expand Success Stack(%d)\n", s->size);
    }
    s->top++;
    s->data[s->top] = val;
    return 1;
}

int pop(Stack *s) {
    if(s == NULL) return 0;
    if(empty(s)) return 0;
    s->top -= 1;
    return 1;
}

void output(Stack *s) {
    printf("Stack = [");
    for(int i = s->top; i >= 0; i--) {
        i != s->top && printf(", ");
        printf("%d", s->data[i]);
    }
    printf("]\n");
    return ;
}

void clear(Stack *s) {
    if(s == NULL) return ;
    free(s->data);
    free(s);
    return;
}

int main() {
    srand(time(0));
    #define max_op 20 
    Stack *s = init(3);
    int op, val;
    for(int i = 0; i < max_op; i++) {
        op = rand() % 4;
        val = rand() % 100;
        switch (op) {
            case 0 :
            case 1 :
            case 2 : {
                printf("push %d to Stack = %d\n", val, push(s, val));
                output(s);
                printf("\n");
            } break;
            case 3 : {
                printf("pop %d to Stack = ", top(s));
                printf("%d\n", pop(s));
                output(s);
                printf("\n");
            } break;
        }
    }
    clear(s);
    return 0;
}

