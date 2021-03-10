/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) 
    {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr)
            return minDepth(root->right) + 1;
        if (root->right == nullptr)
            return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;

        //  BFS
        // int mindepth = 0;
        // std::queue<TreeNode*> node_queue;
        // node_queue.push(root);
        // while (!node_queue.empty())
        // {
        //     int qsize = node_queue.size();
        //     if (qsize > 0)
        //         ++mindepth;
        //     while (qsize > 0)
        //     {
        //         TreeNode* cur = node_queue.front();
        //         node_queue.pop();
        //         if (cur->left == nullptr && cur->right == nullptr)
        //             return mindepth;
        //         if (cur->left)
        //             node_queue.push(cur->left);
        //         if (cur->right)
        //             node_queue.push(cur->right);
        //         --qsize;
        //     }
        // }
        // return mindepth;
    }
};
// @lc code=end

