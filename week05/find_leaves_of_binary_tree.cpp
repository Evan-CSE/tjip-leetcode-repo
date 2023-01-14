/**
 *  TC: O(nlog(n))
 *  MC: O(n)
 *  where 'n' is the number of nodes of the tree
 */

class Solution
{
public:
    map<TreeNode *, int> max_depth; // we don't know if all values are unique so we should map their max_depth with corresponding TreeNode
    int max_number_of_vectors = 0;
    // a node 'n' will be unotouched until max depth from n to leaf
    int find_max_depth(TreeNode *root)
    {
        if (root == NULL)
        {
            max_depth[root] = -1;
            return 0;
        }
        if (max_depth.count(root))
            return max_depth[root];
        int left_max_depth = find_max_depth(root->left);
        int right_max_dept = find_max_depth(root->right);
        if (root->left)
            max_depth[root->left] = left_max_depth;
        if (root->right)
            max_depth[root->right] = right_max_dept;
        max_depth[root] = max(left_max_depth, right_max_dept) + 1;
        max_number_of_vectors = max(max_number_of_vectors, max_depth[root]);
        return max_depth[root];
    }
    vector<vector<int>> findLeaves(TreeNode *root)
    {
        vector<vector<int>> leaves;
        find_max_depth(root);
        map<int, vector<int>> mp;
        for (auto it = max_depth.begin(); it != max_depth.end(); it++)
        {
            if (it->second >= 0)
                mp[it->second].push_back(it->first->val);
        }
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            leaves.push_back(it->second);
        }
        return leaves;
    }
};