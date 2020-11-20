/*************************************************************************
	> File Name: linklist.c
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月09日 星期六 00时31分28秒
 ************************************************************************/

#include "linklist.h"

int insert(LinkedList head, Node *node) {
    Node *p = head;
    while(p->next != NULL) {
        p = p->next;
    }
    p->next = node;
    return 0;
}

