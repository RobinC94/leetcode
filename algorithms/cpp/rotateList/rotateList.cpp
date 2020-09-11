// Source : https://leetcode.com/problems/rotate-list/
// Author : Robin Chen
// Date   : 2020.09.11

/********************************************************************************** 
* 
* Given a linked list, rotate the list to the right by k places, where k is non-negative.
*
* Example 1:
* Input: 1->2->3->4->5->NULL, k = 2
* Output: 4->5->1->2->3->NULL
*               
**********************************************************************************/

// 体力题

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0)
            return head;
        if (head -> next == NULL)
            return head;
        
        ListNode* tmp = head, *rear;
        int len = 1;
        while (tmp -> next != NULL){
            tmp = tmp -> next;
            len++;
        }
        if (k % len == 0)
            return head;
        int pos = len - k%len;
        rear = tmp;
        tmp = head;
        for(int i = 0; i < pos-1; ++i)
            tmp = tmp -> next;
        rear -> next = head;
        head = tmp -> next;
        tmp -> next = NULL;
        return head;
    }
};

// Runtime: 8 ms, faster than 76.36% of C++ online submissions for Rotate List.
// Memory Usage: 12.1 MB, less than 5.04% of C++ online submissions for Rotate List.