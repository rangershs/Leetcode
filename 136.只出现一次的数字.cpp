/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int ret = 0;
        for (const auto& item : nums)
            ret ^= item;
        return ret;
        //  1.遍历数组用Hashtable记录每个元素出现的次数，然后遍历Hashtable
        //  2.遍历数组，元素首次出现放进Hashtable，第2次出现从Hashtable中删除
        //  3.位运算-异或操作
    }
};
// @lc code=end

