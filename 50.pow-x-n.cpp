/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) 
    {
        //  Time exceed
        // if (n == 0 || floalEqual(x, 1.0))
        //     return 1.0;
        // if (floalEqual(x, 0.0))
        //     return 0.0;
        // if (floalEqual(x, -1.0))
        //     return (n > 0 ? x : (-1 * x));
        // int64_t nL = n;
        // if (nL < 0)
        //     nL *= -1;
        // double maxval = 0x7FFFFFFF / (x > 0 ? x : (-1 * x));
        // double ret = 1.0;
        // while (nL > 0)
        // {
        //     if (ret > maxval)
        //         return 0.0;
        //     ret *= x;
        //     --nL;
        // }
        // return (n > 0 ? ret : (1.0 / ret));

        int64_t nL = n;
        if (n < 0)
            nL *= -1;
        // return (n > 0 ? powWithRecursion(x, nL) : 1.0 / powWithRecursion(x, nL));
        return (n > 0 ? powWithIteration(x, nL) : 1.0 / powWithIteration(x, nL));
    }

    double powWithIteration(double x, int64_t n)
    {
        double ret = 1.0;
        double weight = x;
        while (n > 0)
        {
            if ((n & 0x1) != 0)
                ret *= weight;
            weight *= weight;
            n >>= 1;
        }
        return ret;
    }

    double powWithRecursion(double x, int64_t n)
    {
        if (n == 0)
            return 1.0;
        double ret = powWithRecursion(x, n / 2);
        return (n % 2 == 0 ? (ret * ret) : (ret * ret * x));
    }

    bool floalEqual(double x, double y)
    {
        return ((x - y < 0.0000001) && (x - y > -0.0000001));
    }
};
// @lc code=end

