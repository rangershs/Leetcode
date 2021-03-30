/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        if (nums.empty())
            return 0;
        int size = static_cast<int>(nums.size());
        std::vector<int> len_array(size, 1);
        std::vector<int> count_array(size, 1);
        for (int i = size - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < size; ++j)
            {
                if (nums[i] < nums[j])
                {
                    if (len_array[i] < len_array[j] + 1)
                        count_array[i] = count_array[j];
                    else if (len_array[i] == len_array[j] + 1)
                        count_array[i] += count_array[j];
                    len_array[i] = std::max(len_array[i], len_array[j] + 1);
                }
            }
        }
        int max_len = 1;
        for (const auto&item : len_array)
        {
            if (max_len < item)
                max_len = item;
        }
        int max_count = 0;
        for (int k = 0; k < size; ++k)
        {
            if (max_len == len_array[k])
                max_count += count_array[k];
        }
        return max_count;
    }
};
// @lc code=end

