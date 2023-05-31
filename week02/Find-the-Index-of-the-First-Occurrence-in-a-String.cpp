class solution
{
public:
    const static int BASE = 31;
    const static int MOD = 1e9 + 9;
    int find_occurence(stirng &haystack, string &needle)
    {
        int prefix_of_needle[needle.size()];
        long long hashed_needle = 0, current_hash = 0;
        for (int i = 0; i < needle.size(); i++)
        {
            prefix_of_needle[i] = hashed_needle + ((needle[i] - 'a' + 1) * BASE) % MOD;
        }
        int idx = 0, len = 0;
        for (auto &ch : haystack)
        {
            current_hash = (current_hash + ((ch - 'a' + 1) * BASE)) % MOD;
            if (prefix_of_needle[len] == current_hash)
            {
                len++;
            }
            else
            {
                len = 0;
                current_hash = 0;
            }
            idx++;
            if (len == needle.size())
                return needle.size() - idx - 1;
        }
        return -1;
    }
};