/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        if (needle.empty())
            return 0;
        if (haystack.empty() || haystack.size() < needle.size())
            return -1;
        size_t hay_size = haystack.size();
        size_t needle_size = needle.size();
        size_t i = 0;
        size_t j = 0;
        while (i < hay_size && j < needle_size)
        {
            if (haystack[i] == needle[j])
            {
                ++i;
                ++j;
            }
            else
            {
                i = i - j + 1;
                j = 0;
            }
        }
        return (j == needle_size) ? i - j : -1;
    }
};
// @lc code=end

