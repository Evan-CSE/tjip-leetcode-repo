// Approach 1
// Time Complexity: n*n(log(n))
// MC:O(log(n)+n)
class Solution
{
public:
    int b_search(vector<int> &nums, int left, int right, int target)
    {
        int mid, resultIndex = -1;
        while (left <= right)
        {
            mid = (left + right) >> 1;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return resultIndex;
    }
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        set<pair<int, int>> taken;
        for (int i = 0; i < len; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (taken.find({nums[i], nums[j]}) != taken.end())
                    continue;
                int target = -(nums[i] + nums[j]);
                int indx = b_search(nums, j + 1, len - 1, target);
                if (indx != -1)
                {
                    result.push_back({nums[i], nums[j], nums[indx]});
                    taken.insert({nums[i], nums[j]});
                }
            }
        }
        return result;
    }
};