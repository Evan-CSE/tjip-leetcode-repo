// Approach 1
// TC: O(n)
// MC: O(n)
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        map<int, int> mp;
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            mp[nums[i]] = i;
        }
        for (int i = 0; i < len; i++)
        {
            if (mp.find(target - nums[i]) != mp.end() && mp[target - nums[i]] > i)
            {
                ans.push_back(i);
                ans.push_back(mp[target - nums[i]]);
                break;
            }
        }
        return ans;
    }
};

// Approach 2
// TC: O(n*n)
// MC: O(n*n)
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};