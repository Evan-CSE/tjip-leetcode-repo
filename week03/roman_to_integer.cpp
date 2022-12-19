// TC: O(n) where n denotes size of the given string
// MC: O(1)
class Solution
{
public:
    unordered_map<char, int> to_number;
    int subtract(char &prev, char &cur)
    {
        if (prev == 'I' && (cur == 'X' || cur == 'V'))
            return 2;
        if (prev == 'X' && (cur == 'L' || cur == 'C'))
            return 20;
        if (prev == 'C' && (cur == 'D' || cur == 'M'))
            return 200;
        return 0;
    }
    int romanToInt(string &s)
    {
        to_number['I'] = 1;
        to_number['V'] = 5;
        to_number['X'] = 10;
        to_number['L'] = 50;
        to_number['C'] = 100;
        to_number['D'] = 500;
        to_number['M'] = 1000;
        long long int_value = 0;
        char prev = '-';
        for (auto &x : s)
        {
            int_value += to_number[x];
            int_value -= subtract(prev, x);
            prev = x;
        }
        return int_value;
    }
};