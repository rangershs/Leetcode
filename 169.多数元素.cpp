/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        //  1.hashmap
        //  2.sort, n/2
        //  3.select random element
        //  4.poll, approval vs disapproval
        std::sort(nums.begin(), nums.end());
        return (nums.empty() ? 0 : nums[nums.size() / 2]);
    }
};
// @lc code=end

