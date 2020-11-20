/*************************************************************************
	> File Name: linkedlist.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月02日 星期三 19时09分26秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct ListNode {
    int data;
    struct ListNode *next; // C语言这行需要写struct 因为listnode还没重定义完
}ListNode;

typedef struct List {
    ListNode head; //head 是一个结点
    int length;
}List;
//分别定义链表结点和链表
ListNode *init_ListNode(int val) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = val;
    p->next = NULL;
    return p;
}

List *init_List() {
    List *l = (List *)malloc(sizeof(List));
    l->head.next = NULL;
    l->length = 0;
    return l;
}

void clear_node(ListNode *node) {
    if(node == NULL) return ;
    free(node);
    return ;
}

void clear_list(List *l) {
    if(l == NULL) return ;
    ListNode *p = l->head.next, *q;
    while(p) {
        q = p->next;
        clear_node(p);
        p = q;
    }
    free(l);
}

int insert(List *l, int ind, int val) {
    if(l == NULL) return 0;
    if(ind < 0 || ind > l->length) return 0;
    ListNode *p = &(l->head), *node = init_ListNode(val);  
//*node 指向待插入结点的指针
    while(ind--) p = p->next;
    //不能是--ind 否则当ind = 0时会死循环
    node->next = p->next;
    p->next = node;
    l->length += 1;
    return 1;
}

int erase(List *l, int ind) {
    if(l == NULL) return 0;
    if(ind < 0 || ind >= l->length) return 0;
    ListNode *p = &(l->head), *q;
    while(ind--) p = p->next;
    q = p->next;
    p->next = q->next;
    clear_node(q);
    l->length -= 1;
    return 1;
}

void output(List *l) {
    printf("list(%d) = [",l->length);
    for(ListNode *p = l->head.next; p; p = p->next) {
        printf("%d -> ", p->data);
    }
    printf("NULL]\n");
    return ;
}


int main() {
    srand(time(0));
    #define max_op 20
    int op, ind, val;
    List *l = init_List();
    for(int i = 0; i < max_op; i++) {
        op = rand() % 4;
        ind = rand() % (l->length + 3) - 1;
        val = rand() % 100;
        switch(op) {
            case 0 :
            case 1 :
            case 2 : {
                printf("insert %d at %d to List = %d\n", val, ind, insert(l, ind, val));
                output(l);
                printf("\n");
            } break;
            case 3 : {
                printf("erase iterm at %d from List = %d\n", ind, erase(l ,ind));
                output(l);
                printf("\n");
            } break;
        }
    }
    clear_list(l);
    return 0;
}

