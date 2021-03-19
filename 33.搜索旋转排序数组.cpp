/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        // int ret = -1;
        // for (int i = 0; i < static_cast<int>(nums.size()); ++i)
        // {
        //     if (nums[i] == target)
        //     {
        //         ret = i;
        //         break;
        //     }
        // }
        // return ret;

        int ret = -1;
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                ret = mid;
                break;
            }
            if (nums[left] <= nums[mid])
            {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return ret;
    }
};
// @lc code=end

