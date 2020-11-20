/*************************************************************************
	> File Name: Queue.c
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月10日 星期日 16时29分52秒
 ************************************************************************/

#include "head.h"

typedef struct Node {
    int num;
    struct Node *next;
}Node, *LinkedList;

Node insert(LinkedList head, Node *node, int index) {
    Node *p, ret;
    p = &ret;
    ret.num = 0;
    ret.next = head;
    while(p->next && index) {
        p = p->next;
        --index;
    }
    if(index == 0) {
        node->next = p->next;
        p->next = node;
        ret.num = 1;
    }
    return ret;
}

