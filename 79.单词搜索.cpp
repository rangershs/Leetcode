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
        for (int i = 0; i < len; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                ret = check(board, word, visited, i, j, 0);
                if (ret)
                    return ret;
            }
        }
        return ret;
    }

    bool check(
        const vector<vector<char>>& board,
        const string& word,
        vector<vector<bool>>& visited,
        int len,
        int width,
        int index)
    {
        if (index == static_cast<int>(word.size()))
            return true;
        if (board[len][width] != word[index])
            return false;
        visited[len][width] = true;
        bool leftdir = false;
        if (len - 1 >= 0 && !visited[len-1][width])
            leftdir = check(board, word, visited, len-1, width, index+1);
        bool downdir = false;
        if (width - 1 >= 0 && !visited[len][width-1])
            downdir = check(board, word, visited, len, width-1, index+1);
        bool rightdir = false;
        if (len + 1 < static_cast<int>(board.size()) && !visited[len+1][width])
            rightdir = check(board, word, visited, len+1, width, index+1);
        bool updir = false;
        if (width + 1 < static_cast<int>(board[0].size()) && !visited[len][width+1])
            updir = check(board, word, visited, len, width+1, index+1);
        visited[len][width] = false;
        return (leftdir || downdir || rightdir || updir);
    }
};
// @lc code=end

