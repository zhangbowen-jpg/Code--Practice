/*************************************************************************
	> File Name: leetcode-160.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月03日 星期四 15时20分50秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA == NULL || headB == NULL) return NULL;
    struct ListNode *p = headA;
    struct ListNode *q = headB;
    while(p != q) {
        p = p == NULL ? headB : p->next;
        q = q == NULL ? headA : q->next;
    }
    return p;
}
