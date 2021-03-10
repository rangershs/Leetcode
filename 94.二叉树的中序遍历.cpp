/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ivec;
        // inOrderRecursive(root, &ivec);
        inOrderNonRecursive(root, &ivec);
        return ivec;
    }

    void inOrderRecursive(TreeNode* root, vector<int>* ivec)
    {
        if (root != nullptr)
        {
            inOrderRecursive(root->left, ivec);
            ivec->push_back(root->val);
            inOrderRecursive(root->right, ivec);
        }
    }

    void inOrderNonRecursive(TreeNode* root, vector<int>* ivec)
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
                // ivec->push_back(cur->val);
                cur = cur->left;
            }
            cur = nodes.top();
            nodes.pop();
            ivec->push_back(cur->val);
            cur = cur->right;
        }
    }
};
// @lc code=end

