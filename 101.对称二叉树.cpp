/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) 
    {
        if (root == nullptr)
            return true;
        if (root->left == nullptr && root->right == nullptr)
            return true;
        if (root->left == nullptr || root->right == nullptr)
            return false;
        // return isMirror(root->left, root->right);
        return isMirrorNonRecursion(root->left, root->right);
    }

    bool isMirror(TreeNode* lroot, TreeNode* rroot)
    {
        if (lroot == nullptr && rroot == nullptr)
            return true;
        if (lroot == nullptr || rroot == nullptr)
            return false;
        return (lroot->val == rroot->val && isMirror(lroot->left, rroot->right) && isMirror(lroot->right, rroot->left));
    }

    bool isMirrorNonRecursion(TreeNode* lroot, TreeNode* rroot)
    {
        if (lroot->val != rroot->val)
            return false;
        std::queue<TreeNode*> node_queue;
        node_queue.push(lroot);
        node_queue.push(rroot);
        bool flag = true;
        while (!node_queue.empty())
        {
            TreeNode* first_node = node_queue.front();
            node_queue.pop();
            TreeNode* second_node = node_queue.front();
            node_queue.pop();
            if (first_node->left == nullptr && second_node->right == nullptr)
            {
                
            }
            else if (first_node->left == nullptr || second_node->right == nullptr)
            {
                flag = false;
                break;
            }
            else if (first_node->left->val != second_node->right->val)
            {
                flag = false;
                break;
            }
            else
            {
                node_queue.push(first_node->left);
                node_queue.push(second_node->right);
            }

            if (first_node->right == nullptr && second_node->left == nullptr)
            {
                
            }
            else if (first_node->right == nullptr || second_node->left == nullptr)
            {
                flag = false;
                break;
            }
            else if (first_node->right->val != second_node->left->val)
            {
                flag = false;
                break;
            }
            else
            {
                node_queue.push(first_node->right);
                node_queue.push(second_node->left);
            }
        }
        return flag;
    }
};
// @lc code=end

