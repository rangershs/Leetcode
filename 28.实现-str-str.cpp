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
        int hay_size = static_cast<int>(haystack.size());
        int needle_size = static_cast<int>(needle.size());
        int i = 0;
        int j = 0;
        std::vector<int> next(nextIndex(needle));
        //  Warning: sign-comparison between signed and unsigned
        while (i < hay_size && j < needle_size)
        {
            // if (haystack[i] == needle[j])
            // {
            //     ++i;
            //     ++j;
            // }
            // else
            // {
            //     i = i - j + 1;
            //     j = 0;
            // }

            //  KMP
            if (j == -1 || haystack[i] == needle[j])
            {
                ++i;
                ++j;
            }
            else
            {
                j = next[j];
            }
        }
        return (j == needle_size) ? i - j : -1;
    }

    std::vector<int> nextIndex(const std::string& needle)
    {
        //  Warning: operator[] maybe cause memory fault
        std::vector<int> ivec(needle.size() + 1, 0);
        ivec[0] = -1;
        int i = 0;
        int j = -1;
        while (i < needle.size())
        {
            if (j == -1 || needle[i] == needle[j])
            {
                ++i;
                ++j;
                ivec[i] = j;
            }
            else
            {
                j = ivec[j];
            }
        }
        return ivec;
    }
};
// @lc code=end

