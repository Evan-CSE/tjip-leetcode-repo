class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int l = nums.size(), mn = INT_MAX, indx1, indx2;
        bool flag = true;
        for (int i = l - 2; i >= 0 && flag; i--)
        {
            for (int j = i + 1; j < l; j++)
            {
                if (nums[i] < nums[j] && nums[j] < mn)
                {
                    mn = nums[j];
                    indx1 = i;
                    indx2 = j;
                }
            }
            if (mn != INT_MAX)
                flag = false;
        }
        if (mn == INT_MAX)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            swap(nums[indx1], nums[indx2]);
            for (int i = indx1 + 1; i < l; i++)
            {
                for (int j = i + 1; j < l; j++)
                    if (nums[i] > nums[j])
                        swap(nums[i], nums[j]);
            }
        }
    }
};