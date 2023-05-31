// Approach 1
// TC: O(n*n)
// MC: O(2*n)
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        int len = intervals.size();
        for (int i = 0; i < len; i++)
        {
            int finishingTime = intervals[i][1], skipIndx = 1;
            for (int j = i + 1; j < len; j++)
            {
                if (intervals[i][1] >= intervals[j][0])
                    finishingTime = max(intervals[j][1], finishingTime), skipIndx++;
            }
            int sz = result.size();
            if (sz > 0 && result[sz - 1][1] >= intervals[i][0])
                result[sz - 1][1] = max(finishingTime, result[sz - 1][1]);
            else
                result.push_back({intervals[i][0], finishingTime});
            i += skipIndx - 1;
        }
        return result;
    }
};