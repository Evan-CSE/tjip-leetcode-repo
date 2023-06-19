/**
 * @brief
 *  TC: O(log(n))
 *  MC: O(1)
 * where n is the provided number to the function
 */
class Solution
{
public:
    int trailingZeroes(int n)
    {
        int num = 5;
        int trailing_zero_cnt = 0;
        while (num <= n)
        {
            trailing_zero_cnt += (n / num);
            num *= 5;
        }
        return trailing_zero_cnt;
    }
};