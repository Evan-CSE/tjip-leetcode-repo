// TC: O(n*n) where n is the size of the array
// MC: O(n*n) where n is the size of the array

class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<long long, int> sum_occurence;
        for (auto &x : nums1)
            for (auto &y : nums2)
                sum_occurence[x + y]++;
        int total_count = 0;
        for (auto &x : nums3)
            for (auto &y : nums4)
                total_count += sum_occurence[-(x + y)];
        return total_count;
    }
};