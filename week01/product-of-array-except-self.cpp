// Approach 1 (Suffix & Prefix Technique)
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        vector<int> leftSide, RightSide;
        leftSide.push_back(1);
        RightSide.push_back(1);
        for (int i = 1; i < n; i++)
        {
            leftSide.push_back(leftSide[i - 1] * nums[i - 1]);
            RightSide.push_back(RightSide[i - 1] * nums[n - i]);
        }
        reverse(RightSide.begin(), RightSide.end());
        for (int i = 0; i < n; i++)
        {
            ans.push_back(leftSide[i] * RightSide[i]);
        }
        return ans;
    }
};

// Approach 2 (No Suffix or Prefix Array)
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> ans;
        int zeroCount = 0, product = 1;
        for (auto x : nums)
        {
            if (x == 0)
                zeroCount++;
            else
                product *= x;
        }
        for (auto x : nums)
        {
            if (x == 0)
            {
                ans.push_back(zeroCount == 1 ? product : 0);
            }
            else
            {
                ans.push_back(zeroCount >= 1 ? 0 : product / x);
            }
        }
        return ans;
    }
};