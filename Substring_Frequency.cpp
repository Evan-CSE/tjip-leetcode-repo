#include <bits/stdc++.h>

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

vector<int> lps;
vector<int> &generate_lps(string &pattern)
{
    lps.clear();
    lps.resize(pattern.size());
    lps[0] = 0;
    int len = pattern.size(), indx = 0;
    for (int i = 1; i < len;)
    {
        if (pattern[indx] == pattern[i])
        {
            lps[i] = indx + 1;
            indx++, i++;
        }
        else
        {
            if (indx)
                indx = lps[indx - 1];
            else
                lps[i++] = 0;
        }
    }
    return lps;
}

int kmp(string &text, string &pattern, vector<int> &lps)
{
    int matched = 0, text_indx = 0, pattern_indx = 0, len = text.size(), pattern_sz = pattern.size();
    while (text_indx < len)
    {
        if (text[text_indx] == pattern[pattern_indx])
        {
            text_indx++, pattern_indx++;
        }
        else
        {
            if (pattern_indx)
                pattern_indx = lps[pattern_indx - 1];
            else
                text_indx++;
        }
        if (pattern_indx == pattern_sz)
        {
            matched++;
            pattern_indx = lps[pattern_indx - 1];
        }
    }
    return matched;
}

int main()
{
    fast;
    int t, cs = 1;
    string text, pattern;
    cin >> t;
    while (t--)
    {
        cin >> text >> pattern;
        vector<int> lps = generate_lps(pattern);
        cout << "Case " << cs++ << ": ";
        cout << kmp(text, pattern, lps) << endl;
    }
    return 0;
}