/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        //  outer-list -> a
        //  circle-list -> r = b + c
        //  2(a + n1 * r + b) = a + n2 * r + b
        //  ==> a + b = (n2 - 2 * n1) * r
        //  ==> a + b = n * (b + c)
        //  ==> a = n * (b + c) - b
        //  ==> a - c = (n - 1)(b + c)
    }
};
// @lc code=end

