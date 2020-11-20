/*************************************************************************
	> File Name: leetcode203.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月04日 星期五 18时27分09秒
 ************************************************************************/
struct ListNode *removeElements(struct ListNode* head, int val) {
    struct ListNode ret, *p, *q;
    ret.next = head;
    p = &ret;
    while(p->next) {
        if(p->next->val == val) {
            q = p->next;
            p->next = q->next;
            free(q);
        } else {
            p = p->next;
        }
    }
    return ret.next;
}
