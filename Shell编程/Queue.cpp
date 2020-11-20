/*************************************************************************
	> File Name: Queue.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月27日 星期日 18时04分12秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    struct Node *next;
    char name[20];
    struct sockaddr_in addr;
}Node, *LinkedList;


LinkList insert(LinkedList head, Node node, char name) {
    strcpy(name, node.name);
    if (head == NULL) {
        if (index != 0) {
            return head;
        }
        head = node;
        return head;
    }
    if (index == 0) {
        node->next = head.next;
        head.next = node;
        return head;
    }
    Node *current_node = head;
    int count = 0;
    while (current_node->next != NULL && current_node.name != name) {
        current_node = current_node->next;
        count++;
    }
    if (current_node.name = name) {
        node->next = current_node->next;
        current_node->next = node;
    }
    return head;
}

void delete_node(LinkedList head, char *name) {
    if (head == NULL) {
        return head;
    }
    Node *current_node = head;
    int count = 0;
    if (index == 0) {
        head = head->next;
        free(current_node);
        return head;
    }
    while (current_node->next != NULL && current_node.name != name) {
        current_node = current_node->next;
        count++;
    }
    if (current_node.name == name && current_node->next != NULL) {
        Node *delete_node = current_node->next;
        current_node->next = delete_node->next;
        free(delete_node);
    }
    return head;
}


void clear(LinkedList head) {
    Node *current_node = head;
    while (current_node != NULL) {
        Node *delete_node = current_node;
        current_node = current_node->next;
        free(delete_node);
    }
}


void output(LinkedList head) {
    if(head == NULL) {
        return ;
    }
    Node *current_node = head;
    while(current_node != NULL) {
        printf("%s ", current_node->head.name);
        current_node = current_node->next;
    }
    printf("\n");
}

