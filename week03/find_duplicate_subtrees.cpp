/**
 * TC: O(n)
 * MC: O(n)
 * where n denotes number of vertices
 */
class Solution
{
public:
    vector<TreeNode *> duplicates;
    unordered_map<string, int> freq;
    string getHashofTree(TreeNode *current_node)
    {
        if (current_node == NULL)
            return "#";
        string left = getHashofTree(current_node->left);
        string right = getHashofTree(current_node->right);
        string hashedNodes = to_string(current_node->val) + "," + left + "," + right;
        if (freq.count(hashedNodes))
        {
            if (freq[hashedNodes] == 1)
                duplicates.push_back(current_node);
        }
        freq[hashedNodes]++;
        return hashedNodes;
    }
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        getHashofTree(root);
        return duplicates;
    }
};