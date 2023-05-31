// Approach 1
// Time Complexity: n*n*n(log(n))
// MC: O(log(n)+n)
class Solution
{
public:
    int b_search(vector<int> &nums, int left, int right, long long target)
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
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int len = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        set<vector<int>> taken;
        for (int i = 0; i < len; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                for (int k = j + 1; k < len; k++)
                {
                    long long trippleSum = nums[i] * 1ll + nums[j] * 1ll + nums[k] * 1ll;
                    int indx = (b_search(nums, k + 1, len - 1, target * 1ll - trippleSum));
                    if (indx != -1)
                    {
                        vector<int> quadruplets = {nums[i], nums[j], nums[k], nums[indx]};
                        sort(quadruplets.begin(), quadruplets.end());
                        if (taken.find(quadruplets) == taken.end())
                        {
                            taken.insert(quadruplets);
                            result.push_back(quadruplets);
                        }
                    }
                }
            }
        }
        return result;
    }
};