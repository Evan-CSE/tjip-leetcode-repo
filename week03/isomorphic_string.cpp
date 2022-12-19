// TC:O(n) where n denotes size of the given string
// MC:O(1)
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> rplc_with;
        int parent[400];
        for (int i = 0; i < 400; i++)
            parent[i] = -1;
        int indx = 0;
        for (auto &x : s)
        {
            if (rplc_with.count(x) == 0)
            {
                if (parent[t[indx]] != -1 && parent[t[indx]] != x)
                    return false;
                rplc_with[x] = t[indx];
                parent[t[indx]] = x;
            }
            if (rplc_with[x] != t[indx])
                return false;
            indx++;
        }
        return true;
    }
};