/*************************************************************************
	> File Name: leetcode-19.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月03日 星期四 15时19分44秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int count = 1, num = 0;
    struct ListNode *current_node = head,*q = head;
    while(current_node->next != NULL){
        current_node = current_node->next;
        count++;
    }
    if (n == count) {
        head = head->next;
        free(q);
        return head;
    }
    struct ListNode *delete_node = head;
    while(num < count - n - 1) {
        delete_node = delete_node->next;
        num++;
    }
    if(delete_node->next != NULL) {
        struct ListNode *node = delete_node->next;
        delete_node->next = node->next;
        free(node);
    }
    return head;
}


