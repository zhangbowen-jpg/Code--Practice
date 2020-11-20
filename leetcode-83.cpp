/*************************************************************************
	> File Name: leetcode-83.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月03日 星期四 15时20分05秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *delete_node = head;
    while(delete_node && delete_node->next) {
        if(delete_node->next->val == delete_node->val) {
            delete_node->next = delete_node->next->next;
        }
        else{
            delete_node = delete_node->next;
        }
    }
    return head;
}


