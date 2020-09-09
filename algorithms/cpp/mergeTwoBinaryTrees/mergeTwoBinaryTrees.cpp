// https://leetcode.com/problems/merge-two-binary-trees/
// Author : Robin Chen
// Date   : 2017.07.21

/********************************************************************************** 
* 
* Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.
* You need to merge them into a new binary tree. 
* The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. 
* Otherwise, the NOT null node will be used as the node of new tree.
*               
**********************************************************************************/

// 写就行了

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) return NULL;
        else if (t1 == NULL) return t2;
        else if (t2 == NULL) return t1;
        else{
            t1->val += t2->val;
            t1->left = mergeTrees(t1->left, t2->left);
            t1->right = mergeTrees(t1->right, t2->right);
            return t1;
        }
    }
};

// Runtime: 42 ms
// Memory Usage: N/A
