/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        //  while-0 and while-1 may be combined.

        ListNode* head = nullptr;
        ListNode* tail = head;
        int carry = 0;
        while (l1 && l2)    //  while-0
        {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            if (head == nullptr)
            {
                head = new ListNode(sum % 10);
                tail = head;
            }
            else
            {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 || l2)    //  while-1
        {
            int sum = (l1 != nullptr ? l1->val : l2->val) + carry;
            carry = sum / 10;
            if (head == nullptr)
            {
                head = new ListNode(sum % 10);
                tail = head;
            }
            else
            {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            if (l1 != nullptr)
                l1 = l1->next;
            else
                l2 = l2->next; 
        }
        if (carry > 0)
        {
            tail->next = new ListNode(carry);
            tail = tail->next;
        }
        return head;
    }
};
// @lc code=end

