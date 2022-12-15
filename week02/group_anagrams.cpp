// TC: O()
class Solution
{
public:
    const static int MULTIPLIER = 31;
    const static long long MOD = 32416190071;
    long long generate_Hash(string &s)
    {
        long long hash = 1;
        for (auto &x : s)
        {
            hash *= (x + MULTIPLIER);
            if (hash >= MOD)
                hash %= MOD;
        }
        return hash;
    }
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<long long, vector<string>> hashes;
        vector<vector<string>> groups;
        for (auto &x : strs)
        {
            hashes[generate_Hash(x)].push_back(x);
        }
        for (auto &it : hashes)
        {
            groups.push_back(it.second);
        }
        return groups;
    }
};