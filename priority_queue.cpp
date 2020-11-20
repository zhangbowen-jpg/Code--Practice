/*************************************************************************
	> File Name: priority_queue.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月09日 星期六 22时52分03秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
} 

typedef struct priority_queue {
    int *data; //一片连续存储区
    int cnt, size;
} priority_queue;

priority_queue *init(int n) {
    priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
    q->data = (int *)malloc(sizeof(int) * (n + 1));
    q->size = n;
    q->cnt = 0;
    return q;
}

int empty(priority_queue *q) {
    return q->cnt == 0; 
}

int top(priority_queue *q) {
    return q->data[1];
}

int push(priority_queue *q, int val) {
    if(q->cnt == q->size) return 0;
    q->cnt += 1;
    q->data[q->cnt] = val;
    int ind = q->cnt;
    while(ind >> 1 && q->data[ind] > q->data[ind >> 1]) {
        swap(q->data[ind], q->data[ind >> 1]);
        ind >>= 1；
    } 
    return 1;
}

int pop(priority_queue *q) {
    if(empty(q)) return 0;
    swap(q->data[1], q->data[q->cnt]);
    q->cnt--;
    int ind = 1;
    while((ind << 1) <= q->cnt) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if(q->data[l] > q->data[temp]) temp = l;
        if(r <= q->cnt && q->data[r] > q->data[temp]) temp = r; //交换
        if(temp == ind) break;
        swap(q->data[ind], q->data[temp]);
        ind = temp;
    }
    return 1;
}

void clear(priority_queue *q) {
    if(q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    priority_queue *q = init(max_op);
    for(int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        push(q, val);
        printf("push %d to queue\n", q);
    }
    for(int i = 0; i < max_op; i++) {
        printf("%d ", top(q));
        pop(q);
    }
    clear(q);
    return 0;
}


