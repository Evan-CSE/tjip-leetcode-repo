/*
    TC: O(n*m)
    MC:O(n*z)
    where n is size of the vector , m denotes size of individual string and z denotes size of each mapped vector
*/

class Solution
{
public:
    vector<vector<string>> groupStrings(vector<string> &strings)
    {
        map<string, vector<string>> same_tp_str_vc;
        string upper_string;
        int distance;
        vector<vector<string>> grp_of_str;
        for (auto &x : strings)
        {
            upper_string = "";
            distance = 'z' - x[0];
            for (auto &ch : x)
                upper_string += (ch - 'a' + distance) % 26 + 'a';
            same_tp_str_vc[upper_string].push_back(x);
        }
        for (auto it = same_tp_str_vc.begin(); it != same_tp_str_vc.end(); it++)
        {
            grp_of_str.push_back(it->second);
        }
        return grp_of_str;
    }
};