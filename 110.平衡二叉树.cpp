/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //  from top to down, O(n * n)
    bool isBalanced(TreeNode* root) 
    {
        if (root == nullptr)
            return true;
        if (root->left == nullptr && root->right == nullptr)
            return true;
        return (abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right));
    }

    int height(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        return std::max(height(root->left), height(root->right)) + 1;
    }

    //  from down to top, O(n)
};
// @lc code=end

