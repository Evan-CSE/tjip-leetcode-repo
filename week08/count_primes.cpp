/**
 * @brief
 *  TC: O(sqrt(n)log(log(n)))
 * MC: O(n)
 *  where n is the provided number in the function
 */

class Solution
{
public:
    bool isComposite[int(5e6) + 10] = {false};
    void sieve(int upperBound)
    {
        for (int i = 2; i * i <= upperBound; i++)
        {
            if (!isComposite[i])
            {
                for (int j = i * i; j <= upperBound; j += i)
                    isComposite[j] = true;
            }
        }
    }
    int countPrimes(int n)
    {
        sieve(n - 1);
        int prime_cnt = 0;
        for (int i = 2; i < n; i++)
            if (!isComposite[i])
                prime_cnt++;
        return prime_cnt;
    }
};