// TC:O(1)
// MC: O(2n)
class RandomizedSet
{
public:
    mt19937 rnd;
    vector<int> Set;
    unordered_map<int, int> indexOf;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (indexOf.count(val))
            return false;
        Set.push_back(val);
        indexOf[val] = Set.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (!indexOf.count(val))
            return false;
        int del_index = indexOf[val];
        int lastIndx = Set.size() - 1;

        swap(Set[del_index], Set[lastIndx]);

        indexOf[Set[del_index]] = del_index;
        indexOf.erase(val);
        Set.pop_back();
        return true;
    }

    int getRandom()
    {

        return Set[rnd() % Set.size()];
    }
};
