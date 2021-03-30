/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        if (nums.empty())
            return 0;
        int size = static_cast<int>(nums.size());
        std::vector<int> len_array(size, 1);
        for (int i = size - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < size; ++j)
            {
                if (nums[i] < nums[j])
                    len_array[i] = std::max(len_array[i], len_array[j] + 1);
            }
        }
        int max_len = 1;
        for (const auto&item : len_array)
        {
            if (max_len < item)
                max_len = item;
        }
        return max_len;
    }
};
// @lc code=end

