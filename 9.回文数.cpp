/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) 
    {
        //  直接的解法是数字转换为字符串后判断回文字符串
        //  考虑边界条件的基础上反转整数，出现溢出时肯定不是回文数
        //  在反转整数的思路上优化，只反转整数长度的一半即可
        if (x < 0 || (x > 9 && x % 10 == 0))
            return false;
        if (x >= 0 && x <= 9)
            return true;
        int reverted = 0;
        while (x > reverted)
        {
            reverted = reverted * 10 + x % 10;
            x /= 10;
        }
        return (x == reverted || x == reverted / 10);
    }
};
// @lc code=end

