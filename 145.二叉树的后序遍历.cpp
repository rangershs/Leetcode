/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ivec;
        // postOrderRecursive(root, &ivec);
        postOrderNonRecursive(root, &ivec);
        return ivec;
    }

    void postOrderRecursive(TreeNode* root, vector<int>* ivec)
    {
        if (root != nullptr)
        {
            postOrderRecursive(root->left, ivec);
            postOrderRecursive(root->right, ivec);
            ivec->push_back(root->val);
        }
    }

    void postOrderNonRecursive(TreeNode* root, vector<int>* ivec)
    {
        if (root == nullptr)
            return;
        std::stack<TreeNode*> nodes;
        TreeNode* cur = root;
        TreeNode* record = nullptr;
        while (!nodes.empty() || cur != nullptr)
        {
            while (cur)
            {
                nodes.push(cur);
                cur = cur->left;
            }
            cur = nodes.top();
            nodes.pop();
            if (cur->right && cur->right != record)
            {
                nodes.push(cur);
                cur = cur->right;
            }
            else
            {
                ivec->push_back(cur->val);
                record = cur;
                cur = nullptr;
            }
        }
    }
};
// @lc code=end

