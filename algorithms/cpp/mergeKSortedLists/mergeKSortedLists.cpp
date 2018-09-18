// Source : https://oj.leetcode.com/problems/merge-k-sorted-lists/
// Author : Robin Chen
// Date   : 2018.9.15

/********************************************************************************** 
* 
* Given two sorted integer arrays A and B, merge B into A as one sorted array.
* Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
* 
* Example:
*
* Input:
* [
*   1->4->5,
*   1->3->4,
*   2->6
* ]
* Output: 1->1->2->3->4->4->5->6
*               
**********************************************************************************/

// 思路1:
// k个指针遍历这些数组，因为每次都要从k个中选择最小的
// 一个思路就是用最小堆保存当前指针下的数据
// 每掏出一个就要从这个指针表示的链表中取一个
// 所以还要用一个map存每个value对应的指针
// 实际写的过程中注意使用STL自带的back() pop_back()等
// 以及heap的使用方式，最小堆的定义等

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        unordered_map<int,vector<int> > hmap;
        vector<int> hp;
        int lnum = lists.size();
        for(int i = 0; i < lnum; ++i){
            ListNode* l = lists[i];
            if(l != NULL) {
                int val = l->val;
                hmap[val].push_back(i);
                hp.push_back(val);
            }
        }

        make_heap(hp.begin(), hp.end(), greater<int>());


        if(hp.empty()) return NULL;

        ListNode* res = NULL;
        ListNode* tmp;

        while(!hp.empty()){
            int m = hp[0];
            if(res == NULL){
                res = new ListNode(m);
                tmp = res;
            }
            else {
                tmp->next = new ListNode(m);
                tmp = tmp->next;
            }

            int index = hmap[m].back();
            hmap[m].pop_back();
            pop_heap(hp.begin(), hp.end(), greater<int>());

            if(lists[index]->next != NULL){
                lists[index] = lists[index]->next;
                int val = lists[index]->val;
                hmap[val].push_back(index);
                hp.back() = val;
            }

            else{
                hp.pop_back();
            }

            push_heap(hp.begin(), hp.end(), greater<int>());

        }

        return res;   
    }
};

// Status: Accepted
// Runtime: 20 ms
// 66.40%