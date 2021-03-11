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
        // return postOrderSol(root, targetSum);
        // return BFSSol(root, targetSum);
        return recursionSol(root, targetSum);
    }

    bool postOrderSol(TreeNode* root, int targetSum)
    {
        if (root == nullptr)
            return false;
        std::stack<TreeNode*> nodes;
        TreeNode* cur = root;
        TreeNode* record = nullptr;
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
            nodes.pop();
            if (cur->right && cur->right != record)
            {
                nodes.push(cur);
                cur = cur->right;
            }
            else
            {
                if (cur->left == nullptr && cur->right == nullptr)
                {
                    if (sum == targetSum)
                        return true;
                }
                sum -= cur->val;
                record = cur;
                cur = nullptr;
            }
        }
        return false;
    }

    bool BFSSol(TreeNode* root, int targetSum)
    {
        if (root == nullptr)
            return false;
        std::queue<std::pair<TreeNode*, int>> nodes;
        nodes.push(std::pair<TreeNode*, int>(root, root->val));
        while (!nodes.empty())
        {
            std::pair<TreeNode*, int> cur = nodes.front();
            nodes.pop();
            int cur_sum = cur.second;
            if (cur.first->left == nullptr && cur.first->right == nullptr)
            {
                if (cur_sum == targetSum)
                    return true;
            }
            if (cur.first->left)
            {
                nodes.push(std::pair<TreeNode*, int>(cur.first->left, cur.first->left->val + cur_sum));
            }
            if (cur.first->right)
            {
                nodes.push(std::pair<TreeNode*, int>(cur.first->right, cur.first->right->val + cur_sum));
            }
        }
        return false;
    }

    bool recursionSol(TreeNode* root, int targetSum)
    {
        if (root == nullptr)
            return false;
        return recursionSum(root, targetSum, root->val);
    }

    bool recursionSum(TreeNode* root, int targetSum, int sum)
    {
        if (root == nullptr)
            return false;
        if (root->left == nullptr && root->right == nullptr)
        {
            if (targetSum == sum)
                return true;
            else
                return false;
        }
        else if (root->left == nullptr)
            return recursionSum(root->right, targetSum, root->right->val + sum);
        else if (root->right == nullptr)
            return recursionSum(root->left, targetSum, root->left->val + sum);
        else
            return (recursionSum(root->left, targetSum, root->left->val + sum) ||
                    recursionSum(root->right, targetSum, root->right->val + sum));
    }

    //  遍历过程中只有一个变量sum，相当于求二叉树所有节点值的和
};
// @lc code=end

