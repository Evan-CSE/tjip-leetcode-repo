// TC: O(length(s)*log(n))
//  MC: O(n)
class Solution
{
public:
    vector<int> charIndex[26];
    bool is_sub(string &str)
    {
        int lastIndex = -1;
        for (auto &x : str)
        {
            vector<int> &temp = charIndex[x - 'a'];
            auto it = upper_bound(temp.begin(), temp.end(), lastIndex);
            if (it == temp.end())
                return false;
            lastIndex = *it;
        }
        return true;
    }
    int numMatchingSubseq(string &s, vector<string> &words)
    {
        int i = 0, num_of_sub = 0;
        for (int i = 0; i < 26; i++)
            charIndex[i].clear();
        for (auto &x : s)
            charIndex[x - 'a'].push_back(i++);
        for (auto &str : words)
        {
            if (is_sub(str))
                num_of_sub++;
        }
        return num_of_sub;
    }
};