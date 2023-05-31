// Approach 1
// TC: o(n)
// MC: O(n)
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int ValueCount[100040] = {0};
        for (auto x : nums)
            ValueCount[x + 10000]++;
        int cnt = 0;
        for (int i = 20000; i >= 0; i--)
        {
            cnt += ValueCount[i];
            if (cnt >= k)
            {
                return i - 10000;
            }
        }
        return 10000;
    }
};