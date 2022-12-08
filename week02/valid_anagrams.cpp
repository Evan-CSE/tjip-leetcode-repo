// Approach 1:
//  TC: O(nlogn)
// MC: O(n)
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// Approach 2:
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