/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        if (root == nullptr)
            return vector<vector<int>>();
        vector<int> ivec;
        vector<vector<int>> ivecs;
        ivec.push_back(root->val);
        DFSSol(root, targetSum, root->val, &ivec, &ivecs);
        return ivecs;
    }

    void DFSSol(TreeNode* root, int targetSum, int sum, vector<int>* ivec, vector<vector<int>>* ivecs)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
        {
            if (targetSum == sum)
            {
                ivecs->push_back(*ivec);
            }
        }
        if (root->left)
        {
            ivec->push_back(root->left->val);
            DFSSol(root->left, targetSum, sum + root->left->val, ivec, ivecs);
        }
        if (root->right)
        {
            ivec->push_back(root->right->val);
            DFSSol(root->right, targetSum, sum + root->right->val, ivec, ivecs);
        }
        ivec->pop_back();
    }
};
// @lc code=end

