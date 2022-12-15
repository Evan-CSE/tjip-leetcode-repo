//  TC: O(n)
//  MC: O(n)
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> checker(26, 0);
        for (auto x : s)
            checker[x - 'a']++;
        for (auto x : t)
            checker[x - 'a']--;
        for (auto x : checker)
            if (x != 0)
                return false;
        return true;
    }
};