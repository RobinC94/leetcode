// Source : https://oj.leetcode.com/problems/maximum-depth-of-binary-tree/
// Author : Robin Chen
// Date   : 2017.11.22

/********************************************************************************** 
* 
* Given a binary tree, find its maximum depth.
* 
* The maximum depth is the number of nodes along the longest path from the root node 
* down to the farthest leaf node.
*               
**********************************************************************************/

// 凡是可以用递归的算法
// 都可以写成用栈
// 再练一遍

// 思路1：递归

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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if (root -> left == NULL && root -> right == NULL) return 1;
        int l = maxDepth(root -> left);
        int r = maxDepth(root -> right);
        return 1 + (l > r ? l : r);
    }
    
};

// Status: Accepted
// Runtime: 6 ms
// 99.69%

/*********************************************************************************/

// 思路2：栈
// 这里使用的技巧是每一个节点要保存当前层的个数
// 并记录下一层的个数
// 相当于广度优先搜索

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
    int maxDepth(TreeNode* root) {
        if(root == NULL)  
            return 0;  
        int level = 0;  
        queue<TreeNode> q1;
        q1.push(*root);  
        int curNum = 1; //num of nodes left in current level  
        int nextNum = 0; //num of nodes in next level  
        while(!q1.empty())  
        {  
            TreeNode n = q1.front();
            q1.pop();
            curNum--;  
            if(n.left!=NULL)  
            {  
                q1.push(*(n.left));  
                nextNum++;  
            }  
            if(n.right!=NULL)  
            {  
                q1.push(*(n.right));  
                nextNum++;  
            }  
            if(curNum == 0)  
            {  
                curNum = nextNum;  
                nextNum = 0;  
                level++;  
            }  
        }  
        return level;  
    }
    
};

// Status: Accepted
// Runtime: 6 ms
// 99.69%
