// Source : https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/
// Author : Robin Chen
// Date   : 2018.4.5

/********************************************************************************** 
* 
* Given a linked list, remove the nth node from the end of list and return its head.
* 
* For example,
* 
*    Given linked list: 1->2->3->4->5, and n = 2.
* 
*    After removing the second node from the end, the linked list becomes 1->2->3->5.
* 
* Note:
* Given n will always be valid.
* Try to do this in one pass. 
*               
**********************************************************************************/

// 我的思路是先找到第n个node，然后从头和从node两路开搜
// 到结尾的时候从头搜的就是要删掉的
// 只不过要考虑很多边界情况

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head -> next == NULL) return NULL;
        int pos = 0;
        ListNode* tmp = head;
        ListNode* res = head;
        while(pos < n){
            tmp = tmp->next;
            pos++;
        }
        if(tmp == NULL) return head->next;
        while(tmp ->next != NULL){
            tmp = tmp -> next;
            res = res -> next;
        }
        tmp = res -> next;
        res->next = tmp -> next;
        delete(tmp);
        return head;
    }
};

// Status: Accepted
// Runtime: 10 ms
// 53.15%