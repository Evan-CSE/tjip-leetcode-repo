// TC: O(1)
// MC: O(n) where n is the number of operations

class MyHashMap
{
public:
    const static int MAXSIZE = 103880;
    const static int PRIME1 = 91, PRIME2 = 331, PRIME3 = 103879;
    list<pair<int, int>> Map[MAXSIZE] = {};
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
        for (auto it = Map[key].begin(); it != Map[key].end(); it++)
        {
            if ((*it).first == key)
            {
                (*it).second = value;
                return;
            }
        }
        Map[key].insert(Map[key].begin(), {key, value});
    }

    int get(int key)
    {
        key = get_hash(key);
        for (auto it = Map[key].begin(); it != Map[key].end(); it++)
        {
            if ((*it).first == key)
                return (*it).second;
        }
        return -1;
    }

    void remove(int key)
    {
        key = get_hash(key);
        for (auto it = Map[key].begin(); it != Map[key].end(); it++)
        {
            if ((*it).first == key)
            {
                it = Map[key].erase(it);
            }
        }
    }
};
