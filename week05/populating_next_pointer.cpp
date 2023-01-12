/*
    TC: O(n)
    MC: O(width)
    where n is the number of nodes in the tree and width is the maximum width of the tree.
*/

class Solution
{
public:
    bool isPowerOfTwo(int value)
    {
        if (value == 0)
            return false;
        return !(value & (value - 1));
    }
    Node *connect(Node *root)
    {
        if (root == NULL)
            return root;
        queue<Node *> q;
        q.push(root);
        int processed = 0;
        while (!q.empty())
        {
            Node *current_node = q.front();
            processed++;
            q.pop();
            if (isPowerOfTwo(processed + 1))
                current_node->next = NULL;
            else
            {
                current_node->next = q.empty() ? NULL : q.front();
            }
            if (current_node->left)
                q.push(current_node->left);
            if (current_node->right)
                q.push(current_node->right);
        }
        return root;
    }
};