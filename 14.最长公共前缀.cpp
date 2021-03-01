/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if (strs.empty())
            return std::string();
        else if (strs.size() == 1)
            return strs[0];
        else
        {
            std::string first_str(strs[0]);
            for (auto i = 0; i < first_str.size(); ++i)
            {
                char ch = first_str[i];
                for (auto j = 1; j < strs.size(); ++j)
                {
                    if (i >= strs[j].size() || ch != strs[j][i])
                        return first_str.substr(0, i);
                }
            }
            return first_str;
        }
    }
};
// @lc code=end

