#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int len;
string needle, haystack;
vector<int> lsp;
void generate_lsp()
{
    lsp.clear();
    lsp.resize(needle.size());
    lsp[0] = 0;
    int idx = 0;
    for (int i = 1; i < len;)
    {
        if (needle[idx] == needle[i])
        {
            lsp[i] = idx + 1;
            idx++, i++;
        }
        else
        {
            idx = lsp[idx - 1];
            i++;
        }
    }
}

void kmp()
{
    bool f = false;
    int len_h = haystack.size(), text_indx = 0, pattern_indx = 0;
    while (text_indx < len_h)
    {
        if (haystack[text_indx] == needle[pattern_indx])
        {
            text_indx++, pattern_indx++;
        }
        else
        {
            if (pattern_indx == 0)
                text_indx++;
            else
                pattern_indx = lsp[pattern_indx - 1];
        }
        if (pattern_indx == len)
        {
            pattern_indx = lsp[pattern_indx - 1];
            cout << text_indx - len << endl;
            f = true;
        }
    }
    if (!f)
        cout << endl;
}

int main()
{
    fast;
    while (cin >> len >> needle >> haystack)
    {
        generate_lsp();
        kmp();
    }
    return 0;
}