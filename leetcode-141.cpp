/*************************************************************************
	> File Name: leetcode-141.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月03日 星期四 15时20分25秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *p,*q;
    if(head == NULL || head->next == NULL) return false;
    p = head, q = head->next;
    while(q && q->next) {
        if(p == q) return true;
        p = p->next;
        q = q->next->next;
    }
    return false;
}
