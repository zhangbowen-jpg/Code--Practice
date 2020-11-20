/*************************************************************************
	> File Name: leetcode-21.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月03日 星期日 14时12分49秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode ret(0), *p = &ret, *q;
        ret.next = NULL;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                q = l1;
                l1 = l1->next;
            } else {
                q = l2;
                l2 = l2->next;
            }
            p->next = q;
            q->next = NULL;
            p = p->next;
        }
        if(l1) p->next = l1;
        if(l2) p->next = l2;
        return ret.next;
    }
};

