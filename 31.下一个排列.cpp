/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        if (nums.empty())
            return;
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            --i;
        if (i >= 0)
        {
            int j = nums.size() - 1;
            while (j > i && nums[i] >= nums[j])
                --j;
            std::swap(nums[i], nums[j]);
        }
        std::reverse(nums.begin() + i + 1, nums.end());
    }
};
// @lc code=end

