/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int index0 = -1;
        int index1 = -1;

        bool found = false;
        if (nums.size() > 1)
        {
            for (index0=0; index0<nums.size()-1; ++index0)
            {
                for (index1=index0+1; index1<nums.size(); ++index1)
                {
                    if (nums[index0] + nums[index1] == target)
                    {
                        found = true;
                        break;
                    }
                }
                if (found)
                    break;
            }
        }

        // std::map<int, int> imap;
        // for (int i=0; i<nums.size(); ++i)
        //     imap[nums[i]] = i;
        // for (int i=0; i<nums.size(); ++i)
        // {
        //     int remain = target - nums[i];
        //     if (imap.find(remain) != imap.end())
        //     {
        //         int j = imap[remain];
        //         if (i != j)
        //         {
        //             index0 = i;
        //             index1 = j;
        //             break;
        //         }
        //     }
        // }

        return std::vector<int>{index0, index1};
    }
};
// @lc code=end

