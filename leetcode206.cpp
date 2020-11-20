/*************************************************************************
	> File Name: leetcode206.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月04日 星期五 18时40分09秒
 ************************************************************************/
struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL) {
        return head;
    }
    struct ListNode *next_node,*current_node;
    current_node = head->next;
    head->next = NULL;
    while(current_node != NULL) {
        next_node = current_node->next;
        current_node->next = head; //把当前结点接到head前面
        head = current_node;  //向前移动head
        current_node = next_node;  //当前结点指向下一个节点位置。
    }
    return head;
}

