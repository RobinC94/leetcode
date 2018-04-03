// Source : https://oj.leetcode.com/problems/binary-tree-preorder-traversal/
// Author : Robin Chen
// Date   : 2016.11.10

/********************************************************************************** 
* 
* Given a binary tree, return the preorder traversal of its nodes' values.
* 
* For example:
* Given binary tree {1,#,2,3},
* 
*    1
*     \
*      2
*     /
*    3
* 
* return [1,2,3].
* 
* Note: Recursive solution is trivial, could you do it iteratively?
*               
**********************************************************************************/

// 入坑纪念！！！
// 很简单前序遍历
// 然而这题的意义是再次提醒我们
// 凡是递归都可以用栈实现！
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
    vector<int> a;
    vector<int> preorderTraversal(TreeNode* root) {
        PreTrav(root);
        return a;
    }

private:
    void PreTrav(TreeNode* N){
        if(N==NULL)
            return;
        a.push_back(N->val);
        PreTrav(N->left);
        PreTrav(N->right);
    }
};

// Status: Accepted
// Runtime: 4 ms
// 17.86%

/**********************************************************************************/

// 思路2：栈
// 其实就是把前一种思路的vector当栈，然后把顺序倒着写
// pop居然不返回值，也是醉了

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
    vector<int> a;
    vector<int> preorderTraversal(TreeNode* root) {
        PreTrav(root);
        return a;
    }

private:
    void PreTrav(TreeNode* N){
        if(N==NULL)
            return;
        a.push_back(N->val);
        PreTrav(N->left);
        PreTrav(N->right);
    }
};

// Status: Accepted
// Runtime: 3 ms
// 94.15%