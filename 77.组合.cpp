/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> vvi;
        vector<int> vi;
        combineCore(n, k, 1, vi, vvi);
        return vvi;
    }

    void combineCore(int n, int k, int num, vector<int>& vi, vector<vector<int>>& vvi)
    {
        if (static_cast<int>(vi.size()) == k)
        {
            vvi.push_back(vi);
            return;
        }
        if (num >= n + 1)
            return;
        vi.push_back(num);
        combineCore(n, k, num + 1, vi, vvi);
        vi.pop_back();
        combineCore(n, k, num + 1, vi, vvi);
    }
};
// @lc code=end

