class Solution
{
public:
    class Trie
    {
    public:
        bool isEnd;
        shared_ptr<Trie> charNodes[26];
        Trie()
        {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                charNodes[i] = nullptr;
        }
    };
    shared_ptr<Trie> root = make_shared<Trie>();
    void insert(string &s)
    {
        auto current_node = root;
        for (auto &ch : s)
        {
            if (current_node->charNodes[ch - 'a'] == nullptr)
                current_node->charNodes[ch - 'a'] = make_shared<Trie>();
            current_node = current_node->charNodes[ch - 'a'];
        }
        current_node->isEnd = true;
    }
    void makeSuggestions(string &currStr, vector<string> &suggest, shared_ptr<Trie> node)
    {
        if (suggest.size() == 3 || node == nullptr)
            return;
        if (node->isEnd)
        {
            suggest.push_back(currStr);
        }
        for (int i = 0; i < 26; i++)
        {
            if (node->charNodes[i] == nullptr)
                continue;
            currStr.push_back(char(i + 'a'));
            makeSuggestions(currStr, suggest, node->charNodes[i]);
            currStr.pop_back();
        }
    }
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        vector<vector<string>> suggestions;
        string currentPrefix = "";
        for (auto &word : products)
            insert(word);
        auto current_node = root;
        bool f = false;
        for (auto &ch : searchWord)
        {
            vector<string> suggest;
            currentPrefix.push_back(ch);
            if (f || current_node->charNodes[ch - 'a'] == nullptr)
            {
                f = true;
                suggestions.push_back(suggest);
                continue;
            }
            current_node = current_node->charNodes[ch - 'a'];
            makeSuggestions(currentPrefix, suggest, current_node);
            suggestions.push_back(suggest);
        }
        return suggestions;
    }
};
