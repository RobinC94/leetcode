// Source : https://oj.leetcode.com/problems/two-sum/
// Author : Robin Chen
// Date   : 2018.3.24

/********************************************************************************** 
* 
* You are given two linked lists representing two non-negative numbers. 
* The digits are stored in reverse order and each of their nodes contain a single digit. 
* Add the two numbers and return it as a linked list.
* 
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
*               
**********************************************************************************/

// 注意两件事：
// 1. 两个数不等长
// 2. 进位发生在短数的最高位
// p.s. 这题居然是Medium？

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* tmp = result;
        int carry = 0;
        
        while(l1!=NULL || l2!=NULL)
        {
            if(l1!=NULL){
                tmp->val += l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                tmp->val += l2->val;
                l2=l2->next;
            }
            carry=tmp->val/10;
            tmp->val=tmp->val%10;
            if(l1!=NULL || l2!=NULL || carry !=0){
                tmp->next=new ListNode(carry);
                tmp=tmp->next;
            }                
        }
        
        return result;
    }
};

// 运行结果：
// Accepted  54ms 75.30%