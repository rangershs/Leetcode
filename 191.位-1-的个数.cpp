/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        // int ret = 0;
        // int count = 0;
        // while (count < 32)
        // {
        //     if (n & (0x1 << count))
        //         ++ret;
        //     ++count;
        // }
        // return ret;

        int ret = 0;
        while (n)
        {
            ++ret;
            n &= (n - 1);
        }
        return ret;
    }
};
// @lc code=end

