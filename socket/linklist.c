/*************************************************************************
	> File Name: linklist.c
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月05日 星期二 19时04分28秒
 ************************************************************************/
#include "linklist.h"

int insert(LinkedList head, Node *node) {
    Node *p = head;
    while(p->next != NULL) {
        p = p->next;
    }
    p->next = node;
    return ;
}

