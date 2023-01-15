/**
 *  TC: O(n)
 *  MC: O(n)
 * where n is the number of nodes of the tree
 */

class Solution
{
public:
    int value = INT_MAX;
    int idx;
    void traverse_and_find(TreeNode *node)
    {
        if (node == NULL || idx < 0)
            return;
        traverse_and_find(node->left);
        idx--;
        if (idx == 0)
        {
            value = min(node->val, value);
            idx--;
            return;
        }
        traverse_and_find(node->right);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        idx = k;
        traverse_and_find(root);
        return value;
    }
};