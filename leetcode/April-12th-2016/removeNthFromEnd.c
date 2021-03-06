/*
[ref.href] leetcode.com/problems/remove-nth-node-from-end-of-list
"
  Given a linked list, remove the nth node from the end of list and return its head.
  
  For example,
  
     Given linked list: 1->2->3->4->5, and n = 2.
  
     After removing the second node from the end, the linked list becomes 1->2->3->5.
  Note:
  Given n will always be valid.
  Try to do this in one pass.
"
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* node = head;
    int count = 0;
    while (node) {
        ++count;
        node = node->next;
    }
    if (count == n) {
        head = head->next;
    }
    else {
        node = head;
        count = count - n - 1;
        while (count > 0) {
            --count;
            node = node->next;
        }
        if (node->next) node->next = node->next->next;
    }
    return head;
}
