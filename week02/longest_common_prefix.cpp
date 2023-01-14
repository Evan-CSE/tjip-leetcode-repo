// TC: O(n*n)
// MC: O(n*n)

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        unordered_map<string, int> scoreOfString;
        for (auto &x : strs)
        {
            string tmp = "";
            for (auto &s : x)
            {
                tmp += s;
                scoreOfString[tmp]++;
            }
        }
        string common = "";
        for (auto it = scoreOfString.begin(); it != scoreOfString.end(); it++)
        {
            if (it->second == strs.size())
            {
                if (common.size() < it->first.size())
                    common = it->first;
            }
        }
        return common;
    }
};