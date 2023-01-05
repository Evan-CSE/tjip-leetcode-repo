/**
 * TC: O(1)
 * MC: O(n) + O(m) + O(n)
 * where m is the number of calls of put() function
 * where n is the number of distinct key-value pairs
 */

class LRUCache
{
public:
    unordered_map<int, int> key_value;
    unordered_map<int, list<int>::iterator> address_of_key;
    list<int> lru;
    int max_capacity = 0;
    LRUCache(int capacity)
    {
        max_capacity = capacity;
    }

    int get(int key)
    {
        if (key_value.count(key) == 0)
        {
            return -1;
        }
        updatelru(key);
        return key_value[key];
    }

    void put(int key, int value)
    {
        if (max_capacity == key_value.size() && key_value.count(key) == 0)
        {
            evict();
        }
        key_value[key] = value;
        updatelru(key);
    }

    void updatelru(int key)
    {
        if (address_of_key.count(key))
            lru.erase(address_of_key[key]);
        lru.push_front(key);
        address_of_key[key] = lru.begin();
    }

    void evict()
    {
        address_of_key.erase(lru.back());
        key_value.erase(lru.back());
        lru.pop_back();
    }
};
