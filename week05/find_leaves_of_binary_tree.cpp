/**
 *  TC: O(n)
 *  MC: O(n)
 * where 'n' is the number of nodes of this tree
 */
class Solution
{
public:
    // a node 'n' will be unotouched until max depth from n to leaf
    int find_max_depth(TreeNode *root, vector<vector<int>> &leaves)
    {
        if (root == NULL)
        {
            return 0;
        }
        int depth = max(find_max_depth(root->left, leaves), find_max_depth(root->right, leaves)) + 1;
        if (depth == leaves.size() + 1)
            leaves.push_back({});
        leaves[depth - 1].push_back(root->val);
        return depth;
    }
    vector<vector<int>> findLeaves(TreeNode *root)
    {
        vector<vector<int>> leaves;
        find_max_depth(root, leaves);
        return leaves;
    }
};