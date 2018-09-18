// Source : https://oj.leetcode.com/problems/mmerge-two-sorted-lists/
// Author : Robin Chen
// Date   : 2018.4.4

/********************************************************************************** 
* 
* Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
* 
* Example:
* 
* Input: 1->2->4, 1->3->4
* Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l2==NULL) return l1;
        if(l1==NULL) return l2;
        ListNode* tmp;
        if(l1->val <= l2->val){
            tmp = l1;
            l1 = l1->next;
        }
        else{
            tmp = l2;
            l2 = l2->next;
        }
        ListNode* res = tmp;
        while (l1 != NULL || l2 != NULL){
            if(l1 == NULL){
                tmp ->next = l2;
                break;
            }
            else if(l2 == NULL){
                tmp -> next = l1;
                break;
            }
            else{
                if(l1->val >= l2-> val){
                    tmp ->next = l2;
                    l2 = l2->next;
                    tmp = tmp->next;
                }
                else{
                    tmp ->next = l1;
                    l1 = l1->next;
                    tmp = tmp->next;
                }
            }
        }
        return res;
        
    }
};


// Status: Accepted
// Runtime: 8 ms
// 89.88%