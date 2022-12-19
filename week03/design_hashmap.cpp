// TC: O(1)
// MC: O(n) where n is the number of operations

class MyHashMap
{
public:
    const static int MAXSIZE = 103880;
    const static int PRIME1 = 91, PRIME2 = 331, PRIME3 = 103879;
    vector<int> Map[MAXSIZE];
    MyHashMap()
    {
    }
    int get_hash(int value)
    {
        return ((value * PRIME1) + PRIME2) % PRIME3;
    }
    void put(int key, int value)
    {
        key = get_hash(key);
        if (!Map[key].empty())
            Map[key].clear();
        Map[key].push_back(value);
    }

    int get(int key)
    {
        key = get_hash(key);
        if (Map[key].empty())
            return -1;
        return Map[key][0];
    }

    void remove(int key)
    {
        key = get_hash(key);
        if (!Map[key].empty())
            Map[key].clear();
    }
};
