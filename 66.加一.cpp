/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int carry = 0;
        for (auto i = digits.size() - 1; i >= 0; --i)
        {
            int sum = digits[i] + carry;
            if (i == digits.size() - 1)
                sum += 1;
            if (sum > 9)
            {
                digits[i] = 0;
                carry = 1;
                if (i == 0)
                {
                    digits.resize(digits.size() + 1, 0);
                    digits[0] = 1;
                    break;
                }
            }
            else
            {
                digits[i] = sum;
                break;
            }
        }
        return digits;
    }
};
// @lc code=end

