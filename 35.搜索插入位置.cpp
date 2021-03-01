/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return left;

        // STL one-line solution
        // return (lower_bound(nums.begin(), nums.end(), target) - nums.begin());
    }
};
// @lc code=end

