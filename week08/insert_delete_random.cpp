/**
 * @brief
 * TC: O(1)
 * MC:O(n)
 * where n is the number of elements to be inserted
 */

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
        // check if the element is present
        if (indexOf.count(val))
        {
            return false;
        }
        Set.push_back(val);
        indexOf[val] = Set.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (indexOf.count(val))
        {
            int lastIndx = Set.size() - 1;
            int del_Indx = indexOf[val];
            swap(Set[lastIndx], Set[del_Indx]);
            // update latest index
            indexOf[Set[del_Indx]] = del_Indx;
            // delete last element
            Set.pop_back();
            indexOf.erase(val);
            return true;
        }
        return false;
    }

    int getRandom()
    {
        return Set[rnd() % Set.size()];
    }
};
