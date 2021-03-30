/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        if (nums.empty())
            return 0;
        int max_count = 1;
        int size = static_cast<int>(nums.size());
        int count = 1;
        for (int i = 0; i < size; ++i)
        {
            if (i + 1 < size && nums[i] < nums[i+1])
            {
                ++count;
            }
            else
            {
                max_count = std::max(max_count, count);
                count = 1;
            }
        }
        return max_count;
    }
};
// @lc code=end

