/**
 * TC: O(n)
 * MC: O(n)
 * where 'n' is the number of nodes in tree
 */
class Solution
{
public:
    Node *connect(Node *root)
    {
        queue<Node *> q;
        if (root != NULL)
            q.push(root);
        int len;
        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                auto current_node = q.front();
                q.pop();
                if (i + 1 < len)
                    current_node->next = q.front();
                if (current_node->left != NULL)
                    q.push(current_node->left);
                if (current_node->right != NULL)
                    q.push(current_node->right);
            }
        }
        return root;
    }
};