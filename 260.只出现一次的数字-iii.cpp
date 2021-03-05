/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int xor_val = 0;
        for (const auto&item : nums)
            xor_val ^= item;
        int bitone = 1;
        //  不确定符号优先级时，该加括号就加括号
        while ((bitone & xor_val) == 0)
            bitone <<=  1;
        int num1 = 0;
        int num2 = 0;
        for (const auto&item : nums)
        {
            if (item & bitone)
            {
                num1 ^= item;
            }
            else
            {
                num2 ^= item;
            }
        }
        return std::vector<int>{num1, num2};
    }
};
// @lc code=end

