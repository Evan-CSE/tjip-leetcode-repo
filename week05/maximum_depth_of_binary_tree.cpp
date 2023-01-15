/**
 * TC: O(n)
 * MC: O(n)
 * where n is number of nodes in the tree
 */
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        auto left_depth = maxDepth(root->left);
        auto right_depth = maxDepth(root->right);
        return 1 + max(left_depth, right_depth);
    }
};