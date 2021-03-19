/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        // int first = -1;
        // int second = -1;
        // for (int i = 0; i < static_cast<int>(nums.size()); ++i)
        // {
        //     if (nums[i] == target)
        //     {
        //         if (first == -1)
        //             first = i;
        //         second = i;
        //     }
        // }
        // return vector<int>{first, second};

        int first = -1;
        int second = -1;
        if (nums.size() > 0)
        {
            int left = 0;
            int right = static_cast<int>(nums.size()) - 1;
            while (left <= right)
            {
                int mid = (left + right) / 2;
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
                    first = mid;
                    if (mid - 1 >= 0 && nums[mid - 1] == target)
                        right = mid - 1;
                    else
                        break;
                }
            }

            left = 0;
            right = static_cast<int>(nums.size()) - 1;
            while (left <= right)
            {
                int mid = (left + right) / 2;
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
                    second = mid;
                    if (mid + 1 < static_cast<int>(nums.size()) && nums[mid + 1] == target)
                        left = mid + 1;
                    else
                        break;
                }
            }
        }
        return vector<int>{first, second};
    }
};
// @lc code=end

