/*
    TC: O(n)
    MC: O(n)
    where n is the number of total messages
*/
class Logger
{
public:
    unordered_map<string, int> is_allowable_now;
    Logger()
    {
        is_allowable_now.clear();
    }

    bool shouldPrintMessage(int timestamp, string message)
    {
        if (is_allowable_now.count(message))
        {
            if (is_allowable_now[message] <= timestamp)
            {
                is_allowable_now[message] = timestamp + 10;
                return true;
            }
            return false;
        }
        is_allowable_now[message] = timestamp + 10;
        return true;
    }
};
