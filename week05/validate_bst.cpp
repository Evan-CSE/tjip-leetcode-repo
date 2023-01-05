/**
 * TC : O(n)
 * MC: O(n)
 */
class Solution
{
public:
    bool isValidBST(TreeNode *root, long long L = LLONG_MIN, long long R = LLONG_MAX)
    {
        if (root == NULL)
            return true;
        if (L > (long long)root->val || (long long)root->val > R)
            return false;
        auto left = isValidBST(root->left, L, (long long)root->val - 1);
        auto right = isValidBST(root->right, (long long)root->val + 1, R);
        return left && right;
    }
};