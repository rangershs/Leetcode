/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode* heada = headA;
        ListNode* headb = headB;
        while (headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
            if (headA == nullptr && headB == nullptr)
                break;
            if (headA == nullptr)
                headA = headb;
            if (headB == nullptr)
                headB = heada;
        }
        return headA;
    }
};
// @lc code=end

