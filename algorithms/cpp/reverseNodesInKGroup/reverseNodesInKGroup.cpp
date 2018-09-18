// Source : https://leetcode.com/problems/reverse-nodes-in-k-group/
// Author : Robin Chen
// Date   : 2018.9.18

/********************************************************************************** 
* 
* Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
*
* k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
*
* Example:
*
* Given this linked list: 1->2->3->4->5
*
* For k = 2, you should return: 2->1->4->3->5
*
* For k = 3, you should return: 3->2->1->4->5
*
* Note:
*
* Only constant extra memory is allowed.
* You may not alter the values in the list's nodes, only nodes itself may be changed.
*               
**********************************************************************************/

// 感觉是算法领域之外，链表的操作细节上最难的题了
// 主要思路包括：
// 1. 反正每次反转前都要探索剩余链表的长度，不如先遍历得到链表总长度方便判断
// 2. 反转后头节点的位置发生变化，因此用一个不变的辅助头节点得到修改后的头节点位置，输出时忽略该辅助节点
// 3. 每次反转前保存该轮反转的头节点，反转后就变成了尾节点，函数输出新的头节点，减少一次遍历
// 其它都是链表操作的细节

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
    ListNode* reverseNextK(ListNode *head, int k)
    {
        ListNode* n = head;
        ListNode* ori = head;
        head = head->next;
        n->next = NULL;
        int num = 1;
        while(num < k)
        {
            ListNode* tmp = head->next;
            head->next = n;
            n = head;
            head = tmp;
            num++;
        }
        ori->next = head;
        return n;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k <= 1)
            return head;
        ListNode* tmp = head;
        int len = 0;
        while(tmp != NULL){
            ++len;
            tmp = tmp -> next;
        }
        ListNode* res = new ListNode(0);
        res -> next = head;
        tmp = head;
        ListNode* pre = res;
        
        while(len >= k){
            len -= k;
            ListNode* cur = tmp;
            tmp = reverseNextK(tmp, k);
            pre->next = tmp;
            pre = cur;
            tmp = pre->next;
        }
        return res->next;
        
    }
};


// Status: Accepted
// Runtime: 16 ms
// 54.81%