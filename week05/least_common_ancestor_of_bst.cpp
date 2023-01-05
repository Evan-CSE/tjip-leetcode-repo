/**
 * TC: O(n)
 * MC: O(n)
 *
 */
class Solution
{
public:
    TreeNode *search_p_and_q(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;
        if (root->val == p->val || root->val == q->val)
            return root;
        auto left = search_p_and_q(root->left, p, q);
        auto right = search_p_and_q(root->right, p, q);
        if (left && right)
            return root;
        return left ? left : right;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return search_p_and_q(root, p, q);
    }
};