/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        if (text1.empty() || text2.empty())
            return 0;
        int size1 = static_cast<int>(text1.size());
        int size2 = static_cast<int>(text2.size());
        std::vector<std::vector<int>> vvec(size1, std::vector<int>(size2, 0));
        //  [size1+1, size2+1] better than [size1, size2]
        vvec[0][0] = text1[0] == text2[0] ? 1 : 0;
        for (int j = 1; j < size2; ++j)
            vvec[0][j] = text1[0] == text2[j] ? 1 : vvec[0][j-1];
        for (int i = 1; i < size1; ++i)
            vvec[i][0] = text1[i] == text2[0] ? 1 : vvec[i-1][0];
        for (int i = 1; i < size1; ++i)
        {
            for (int j = 1; j < size2; ++j)
            {
                if (text1[i] == text2[j])
                {
                    vvec[i][j] = vvec[i-1][j-1] + 1;
                }
                else
                {
                    vvec[i][j] = std::max(vvec[i-1][j], vvec[i][j-1]);
                }
            }
        }
        return vvec[size1-1][size2-1];
    }
};
// @lc code=end

