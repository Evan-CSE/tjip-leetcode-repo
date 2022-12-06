// Approach 1:
//  TC: O(n)
//  MC: O(1)
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int l = s.size(), x = 0, y = 0;
        if (l != t.size())
            return false;
        for (int i = 0; i < l; i++)
        {
            x ^= s[i];
            y ^= t[i];
        }
        if (x == y)
            return true;
        return false;
    }
};

// Approach 2:
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

// Approach 3:
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