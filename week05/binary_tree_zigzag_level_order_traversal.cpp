/**
 * TC: O(n)
 * MC: O(w)
 * where 'n' denotes number of nodes in the tree
 * and 'w' denotes maximum width of the tree
 */
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        int len, level = 1;
        if (root)
            q.push(root);
        vector<vector<int>> zigzag_level_vc;
        while (!q.empty())
        {
            len = q.size();
            vector<int> same_level_nodes;
            for (int i = 0; i < len; i++)
            {
                auto current_node = q.front();
                q.pop();
                same_level_nodes.push_back(current_node->val);
                if (current_node->left)
                {
                    q.push(current_node->left);
                }
                if (current_node->right)
                {
                    q.push(current_node->right);
                }
            }
            if (level % 2 == 0)
            {
                reverse(same_level_nodes.begin(), same_level_nodes.end());
            }
            zigzag_level_vc.push_back(same_level_nodes);
            level++;
        }
        return zigzag_level_vc;
    }
};