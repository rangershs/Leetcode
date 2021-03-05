/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) 
    {
        //  1.数组或字符串模拟加法操作
        //  2.位运算实现加法
        //      2.1 string xor string
        //      2.2 string & string
        int64_t numa = std::stol(a);
        int64_t numb = std::stol(b);
        while (numb)
        {
            int64_t result = numa ^ numb;
            numb = (numa & numb) << 1;
            numa = result;
        }
        return std::to_string(numa);
    }
};
// @lc code=end

