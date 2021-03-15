/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if (s.empty())
            return 0;
        const char* left = s.c_str();
        const char* right = left + 1;
        std::unordered_set<char> charset;
        charset.insert(*left);
        int max_len = 1;
        while (*right != '\0')
        {
            if (charset.find(*right) == charset.end())
            {
                charset.insert(*right);
                ++right;
            }
            else
            {
                max_len = std::max(max_len, static_cast<int>(charset.size()));
                charset.erase(*left);
                ++left;
                if (left == right)
                {
                    charset.insert(*right);
                    ++right;
                }
            }
        }
        max_len = std::max(max_len, static_cast<int>(charset.size()));
        return max_len;
    }
};
// @lc code=end

