/**
 * @brief
 *  TC: O(log(n))
 *  MC: O(1)
 * where n is number provided to the function
 */

class Solution
{
public:
    int mySqrt(int x)
    {
        long long sq_root = 0, l = 1, r = x, mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (mid * mid <= x)
            {
                sq_root = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return sq_root;
    }
};