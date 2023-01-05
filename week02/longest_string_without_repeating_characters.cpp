// TC: O(n)
//  MC: O(300) === O(1)

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> FrequencyCount(300, 0);
        int count = 0, longestStr = 0, left = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (!FrequencyCount[s[i]])
            {
                count++;
                FrequencyCount[s[i]]++;
                longestStr = max(longestStr, count);
            }
            else
            {
                while (s[left] != s[i])
                {
                    FrequencyCount[s[left]]--;
                    left++;
                }
                left++;
                FrequencyCount[s[i]] = 1;
                if (left == s.size())
                    break;
                count = i - left + 1;
            }
        }
        return longestStr;
    }
};