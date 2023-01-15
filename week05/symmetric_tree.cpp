/**
 * TC: O(n)
 * MC: O(n)
 * where n is the number of nodes in the tree
 */
class Solution
{
public:
    bool isMirrored(TreeNode *lchild, TreeNode *rchild)
    {
        if (lchild == NULL || rchild == NULL)
            return lchild == rchild;
        if (lchild->val != rchild->val)
            return false;
        return isMirrored(lchild->left, rchild->right) && isMirrored(lchild->right, rchild->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return isMirrored(root->left, root->right);
    }
};
