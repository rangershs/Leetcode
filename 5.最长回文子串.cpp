/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    // string longestPalindrome(string s) 
    // {
    //     if (s.empty())
    //         return s;
    //     int left = 0;
    //     int right = 0;
    //     for (int i = 0; i < static_cast<int>(s.size()); ++i)
    //     {
    //         std::pair<int, int> p1 = expandFromCenter(s, i, i);
    //         std::pair<int, int> p2 = std::make_pair(0, 0);
    //         if (i + 1 < static_cast<int>(s.size()) && s[i] == s[i + 1])
    //             p2 = expandFromCenter(s, i, i + 1);
    //         if (p1.second - p1.first > right - left)
    //         {
    //             left = p1.first;
    //             right = p1.second;
    //         }
    //         if (p2.second - p2.first > right - left)
    //         {
    //             left = p2.first;
    //             right = p2.second;
    //         }
    //     }
    //     return s.substr(left, right - left + 1);
    // }

    // std::pair<int, int> expandFromCenter(const std::string& str, int left, int right)
    // {
    //     int size = static_cast<int>(str.size());
    //     while (left >= 0 && right < size)
    //     {
    //         if (str[left] == str[right])
    //         {
    //             --left;
    //             ++right;
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }
    //     return std::make_pair(++left, --right);
    // }

    string longestPalindrome(string s)
    {
        int size = static_cast<int>(s.size());
        std::vector<std::vector<bool>> vvec;
        vvec.resize(size);
        for (int i = 0; i < size; ++i)
            vvec[i].resize(size);
        int left = 0;
        int right = 0;
        for (int len = 0; len < size; ++len)
        {
            for (int i = 0; i < size; ++i)
            {
                int j = i + len;
                if (j >= size)
                    break;
                if (i == j)
                {
                    vvec[i][j] = true;
                }
                else if (i + 1 == j && s[i] == s[j])
                {
                    vvec[i][j] = true;
                }
                else
                {
                    if (vvec[i+1][j-1] && s[i] == s[j])
                        vvec[i][j] = true;
                    else
                        vvec[i][j] = false;
                }
                if (vvec[i][j] && j - i > right - left)
                {
                    left = i;
                    right = j;
                }
            }
        }
        return s.substr(left, right - left + 1);
    }
};
// @lc code=end

