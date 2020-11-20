/*************************************************************************
	> File Name: Queue2.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月03日 星期四 19时11分41秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node, *LinkedList;

Node insert(LinkedList head, Node *node, int index) {
    Node *p, ret;
    p = &ret;
    ret.data = 0;
    ret.next = head;
    while (p->next && index) {
        p = p->next;
        --index;
    }
    if (index == 0) {
        node->next = p->next;
        p->next = node;
        ret.data = 1;
    }
    return ret;
}

void output(LinkedList head) {
    Node *p = head;
    while (p) {
        printf("%d", p->data);
        if (p->next) {
            printf(" ");
        }
        p = p->next;
    }
    printf("\n");
}

void clear(LinkedList head) {
    Node *p, *q;
    p = head;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    return ;
}

int main() {
    LinkedList linkedlist = NULL;
    Node *p, ret;
    int n, num, loc;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &loc, &num);
        p = (Node *)malloc(sizeof(Node));
        p->data = num;
        p->next = NULL;
        ret = insert(linkedlist, p, loc);
        linkedlist = ret.next;
        printf("%s\n", ret.data ? "success" : "failed");
    }
    output(linkedlist);
    clear(linkedlist);
    return 0;
}
