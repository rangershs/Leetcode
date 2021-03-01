/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int subsum = 0;
        int maxsum = nums[0];
        for (auto i = 0; i < nums.size(); ++i)
        {
            if (subsum + nums[i] < nums[i])
                subsum = nums[i];
            else
                subsum = subsum + nums[i];
            maxsum = std::max(maxsum, subsum);
        }
        return maxsum;
    }
};
// @lc code=end

