/**
 *
 *
 */

class Trie
{
private:
    class TrieNode
    {
    public:
        const static int LIMIT = 26;
        bool isEnd;
        shared_ptr<TrieNode> charArr[LIMIT];
        TrieNode()
        {
            for (int i = 0; i < LIMIT; i++)
                charArr[i] = NULL;
            isEnd = false;
        }
    };

public:
    shared_ptr<TrieNode> root;
    Trie()
    {
        root = make_shared<TrieNode>();
    }

    void insert(string word)
    {
        auto current_node = root;
        for (auto &ch : word)
        {
            int indx = ch - 'a';
            if (current_node->charArr[indx] == NULL)
            {
                current_node->charArr[indx] = make_shared<TrieNode>();
            }
            current_node = current_node->charArr[indx];
        }
        current_node->isEnd = true;
    }

    bool search(string word, bool isPrefix = false)
    {
        auto current_node = root;
        for (auto &ch : word)
        {
            int idx = ch - 'a';
            if (current_node->charArr[idx] == NULL)
                return false;
            current_node = current_node->charArr[idx];
        }
        return isPrefix || current_node->isEnd;
    }

    bool startsWith(string prefix)
    {
        return search(prefix, true);
    }
};
