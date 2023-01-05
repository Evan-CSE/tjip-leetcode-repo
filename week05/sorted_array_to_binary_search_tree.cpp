/*
    TC: O(n)
    MC: O(n)
*/
class Solution
{
public:
    TreeNode *findBST(vector<int> &nums, int L, int R)
    {
        if (L > R)
            return NULL;
        int mid = L + (R - L) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = findBST(nums, L, mid - 1);
        root->right = findBST(nums, mid + 1, R);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return findBST(nums, 0, nums.size() - 1);
    }
};