// Source : https://leetcode.com/problems/swap-nodes-in-pairs/
// Author : Robin Chen
// Date   : 2018.9.18

/********************************************************************************** 
* 
* Given a linked list, swap every two adjacent nodes and return its head.
*
* Example:
* 
* Given 1->2->3->4, you should return the list as 2->1->4->3.
* Note:
*
* Your algorithm should use only constant extra space.
* You may not modify the values in the list's nodes, only nodes itself may be changed.
*               
**********************************************************************************/

// 基本操作

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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* tmp = head;
        head = head->next;
        tmp->next = head->next;
        head->next = tmp;
        ListNode* res = head;
        head = tmp -> next;
        while(head != NULL && head->next != NULL){
            tmp->next = head->next;
            tmp = head;
            head = head->next;
            tmp->next = head->next;
            head->next = tmp;
            head = tmp -> next;
        }
        return res;
        
    }
};

// Status: Accepted
// Runtime: 4 ms
// 36.94%