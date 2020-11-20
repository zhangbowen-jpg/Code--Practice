/*************************************************************************
	> File Name: leetcode-203.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月03日 星期四 15时21分09秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *delete_node = head;
    if(delete_node){
        while(delete_node->val == val) {
            if(delete_node->next == NULL) {
                return NULL;
            }
            delete_node = delete_node->next;
        }
        head = delete_node;
        while(delete_node != NULL) {
            if(delete_node->val == val) {
                delete_node = head;
            }
            if(delete_node->next != NULL && delete_node->next->val == val) {
                delete_node->next = delete_node->next->next;
            }
            delete_node = delete_node->next;
        }
    }
    return head;
}


