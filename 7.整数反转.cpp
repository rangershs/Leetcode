/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) 
    {
        int ret = 0;

        //  CPP正数和负数的除法、求模后符号位不变
        //  直接在while循环中完成求模和反转运算，不需要额外的空间和迭代运算
        //  反转后的结果不能超过int类型表示的范围INT_MIN ~ INT_MAX
        while (x != 0)
        {
            int remain = x % 10;
            x /= 10;

            if (ret > INT_MAX/10 ||
                (ret == INT_MAX/10 && remain > INT_MAX % 10))
            {
                ret = 0;
                break;
            }
            if (ret < INT_MIN/10 ||
                (ret == INT_MIN/10 && remain < INT_MIN % 10))
            {
                ret = 0;
                break;
            }

            ret = ret * 10 + remain;
        }
        
        return ret;
    }
};
// @lc code=end

