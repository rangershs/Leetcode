/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        vector<vector<int>> sum_array(grid.size(), vector<int>(grid[0].size()));
        sum_array[0][0] = grid[0][0];
        for (int j = 1; j < grid[0].size(); ++j)
            sum_array[0][j] = sum_array[0][j-1] + grid[0][j];
        for (int i = 1; i < grid.size(); ++i)
            sum_array[i][0] = sum_array[i-1][0] + grid[i][0];
        for (int i = 1; i < grid.size(); ++i)
        {
            for (int j = 1; j < grid[0].size(); ++j)
            {
                sum_array[i][j] = std::min(sum_array[i-1][j], sum_array[i][j-1]) + grid[i][j];
            }
        }
        return sum_array[grid.size()-1][grid[0].size()-1];
    }
};
// @lc code=end

