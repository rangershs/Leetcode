/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> vvi;
        permuteCore(nums, 0, vvi);
        return vvi;
    }

    void permuteCore(vector<int>& nums, int index, vector<vector<int>>& vvi)
    {
        if (index >= static_cast<int>(nums.size()))
            return;
        if (index == static_cast<int>(nums.size()) - 1)
        {
            vvi.push_back(nums);
            return;
        }
        for (int i = index; i < static_cast<int>(nums.size()); ++i)
        {
            std::swap(nums[index], nums[i]);
            permuteCore(nums, index + 1, vvi);
            std::swap(nums[index], nums[i]);
        }
    }
};
// @lc code=end

