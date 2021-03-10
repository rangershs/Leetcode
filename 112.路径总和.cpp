/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if (root == nullptr)
            return false;
        std::stack<TreeNode*> nodes;
        TreeNode* cur = root;
        int sum = 0;
        while (!nodes.empty() || cur != nullptr)
        {
            while (cur)
            {
                nodes.push(cur);
                sum += cur->val;
                cur = cur->left;
            }
            cur = nodes.top();
            node.pop();
            
        }
        
    }
};
// @lc code=end

