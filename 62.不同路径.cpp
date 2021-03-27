/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        if (m <= 0 || n <= 0)
            return 0;
        vector<vector<int>> path_array(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i)
            path_array[i][0] = 1;
        for (int j = 0; j < n; ++j)
            path_array[0][j] = 1;
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                path_array[i][j] = path_array[i-1][j] + path_array[i][j-1];
            }
        }
        return path_array[m-1][n-1];
    }
};
// @lc code=end

