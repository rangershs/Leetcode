/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        if (board.empty() || word.empty())
            return false;
        bool ret = false;
        int len = static_cast<int>(board.size());
        int width = 0;
        if (len > 0)
            width = static_cast<int>(board[0].size());
        vector<vector<bool>> visited(len, vector<bool>(width));
        vector<vector<int>> direction{ { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };
        for (int i = 0; i < len; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                ret = check(board, word, direction, visited, i, j, 0);
                if (ret)
                    return ret;
            }
        }
        return ret;
    }

    bool check(
        const vector<vector<char>>& board,
        const string& word,
        const vector<vector<int>>& direction,
        vector<vector<bool>>& visited,
        int len,
        int width,
        int index)
    {
        if (board[len][width] != word[index])
            return false;
        if (index == static_cast<int>(word.size()) - 1)
            return true;
        
        visited[len][width] = true;
        bool flag = false;
        for (const auto&item : direction)
        {
            int new_len = len + item[0];
            int new_width = width + item[1];
            if (new_len >= 0 && new_len < static_cast<int>(board.size()) &&
                new_width >=0 && new_width < static_cast<int>(board[0].size()) &&
                !visited[new_len][new_width])
            {
                flag = check(board, word, direction, visited, new_len, new_width, index+1);
                if (flag)
                    break;
            }
        }
        visited[len][width] = false;
        return flag;
    }
};
// @lc code=end

