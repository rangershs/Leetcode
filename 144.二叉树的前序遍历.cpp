/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ivec;
        // preOrderRecursive(root, &ivec);
        preOrderNonRecursive(root, &ivec);
        return ivec;
    }

    void preOrderRecursive(TreeNode* root, vector<int>* ivec)
    {
        if (root != nullptr)
        {
            ivec->push_back(root->val);
            preOrderRecursive(root->left, ivec);
            preOrderRecursive(root->right, ivec);
        }
    }

    void preOrderNonRecursive(TreeNode* root, vector<int>* ivec)
    {
        if (root == nullptr)
            return;
        std::stack<TreeNode*> nodes;
        TreeNode* cur = root;
        while (!nodes.empty() || cur != nullptr)
        {
            while (cur)
            {
                nodes.push(cur);
                ivec->push_back(cur->val);
                cur = cur->left;
            }
            cur = nodes.top();
            nodes.pop();
            cur = cur->right;
        }
    }
};
// @lc code=end

