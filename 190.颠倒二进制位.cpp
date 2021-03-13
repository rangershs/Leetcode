/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        // uint32_t ret = 0;
        // int32_t power = 31;
        // while (n != 0)
        // {
        //     ret += ((n & 0x1) << power);
        //     n >>= 1;
        //     power -= 1;
        // }
        // return ret;

        n = ((n & 0xFFFF0000) >> 16) | ((n & 0xFFFF) << 16);
        n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8);
        n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4);
        n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};
// @lc code=end

