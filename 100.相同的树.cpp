/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        // if (p == nullptr && q == nullptr)
        //     return true;
        // if (p == nullptr || q == nullptr)
        //     return false;
        // if (p->val != q->val)
        //     return false;
        // return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
        //  时间复杂度O(max{m,n})，不超过最小的二叉树的节点数
        //  空间复杂度O(max{len(m), len(n)})，不超过最小的二叉树的高度，最坏情况下就是节点数

        // BFS
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr || q == nullptr)
            return false;
        if (p->val != q->val)
            return false;
        std::queue<TreeNode*> pqueue;
        std::queue<TreeNode*> qqueue;
        pqueue.push(p);
        qqueue.push(q);
        while (!pqueue.empty() && !qqueue.empty())
        {
            int psize = static_cast<int>(pqueue.size());
            int qsize = static_cast<int>(qqueue.size());
            if (psize != qsize)
                break;
            while (psize > 0)
            {
                if (pqueue.front() == nullptr && qqueue.front() == nullptr)
                {
                    pqueue.pop();
                    qqueue.pop();
                    --psize;
                }
                else if (pqueue.front() == nullptr || qqueue.front() == nullptr)
                {
                    return false;
                }
                else if (pqueue.front()->val != qqueue.front()->val)
                {
                    return false;
                }
                else
                {
                    TreeNode* pnode = pqueue.front();
                    TreeNode* qnode = qqueue.front();
                    pqueue.pop();
                    qqueue.pop();
                    --psize;
                    pqueue.push(pnode->left);
                    pqueue.push(pnode->right);
                    qqueue.push(qnode->left);
                    qqueue.push(qnode->right);
                }
            }
        }
        if (pqueue.empty() && qqueue.empty())
            return true;
        else
            return false;
    }
};
// @lc code=end

