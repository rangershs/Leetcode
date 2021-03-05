/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) 
    {
        // if (n == 1)
        //     return 1;
        // if (n == 2)
        //     return 2;
        // return climbStairs(n - 1) + climbStairs(n - 2);

        //  dp + dynamic array
        int first = 0;
        int second = 1;
        for (int i = 1; i <= n; ++i)
        {
            int next = first + second;
            first = second;
            second = next;
        }
        return second;
    }
};
// @lc code=end

