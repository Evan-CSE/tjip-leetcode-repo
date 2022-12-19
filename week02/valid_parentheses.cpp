// TC: O(N)
// MC: O(N)
class Solution
{
public:
    bool isValid(char &opn_bracket, char &closing_bracket)
    {
        return (opn_bracket == '(' && closing_bracket == ')') || (opn_bracket == '{' && closing_bracket == '}') || (opn_bracket == '[' && closing_bracket == ']');
    }
    bool isValid(string &s)
    {
        stack<char> stk;
        for (auto &x : s)
        {
            if (x == '(' || x == '{' || x == '[')
            {
                stk.push(x);
                continue;
            }
            else
            {
                if (stk.empty())
                    return false;
                if (!isValid(stk.top(), x))
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};