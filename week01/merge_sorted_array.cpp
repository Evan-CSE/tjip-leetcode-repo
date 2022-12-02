// Approach 1
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (n == 0)
            return;
        if (m == 0)
        {
            int indx = 0;
            while (indx < n)
                nums1[indx] = nums2[indx], indx++;
            return;
        }
        int leftArr[m], rightArr[n];

        for (int i = 0; i < m; i++)
            leftArr[i] = nums1[i];
        for (int i = 0; i < n; i++)
            rightArr[i] = nums2[i];
        int leftIndex = 0, rightIndex = 0, currentIndex = 0;
        while (leftIndex < m && rightIndex < n)
        {
            if (leftIndex < m && leftArr[leftIndex] <= rightArr[rightIndex])
            {
                nums1[currentIndex++] = leftArr[leftIndex++];
            }
            else
            {
                nums1[currentIndex++] = rightArr[rightIndex++];
            }
        }
        while (leftIndex < m)
            nums1[currentIndex++] = leftArr[leftIndex++];
        while (rightIndex < n)
            nums1[currentIndex++] = rightArr[rightIndex++];
    }
};