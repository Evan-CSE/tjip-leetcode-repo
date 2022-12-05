// Approach 1
// TC: nlog(n)
// MC: O(1)
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int l = nums.size();
        sort(nums.begin(), nums.end());
        return nums[l / 2];
    }
};

// Approach 2
// TC: O(n)
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cnt = 0, ans = -1;
        for (auto x : nums)
        {
            if (!cnt)
            {
                cnt++;
                ans = x;
            }
            if (ans == x)
                cnt++;
            else
                cnt--;
        }
        return ans;
    }
};