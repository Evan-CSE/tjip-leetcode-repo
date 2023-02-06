/**
 * @brief
 * TC: O(nlogn)
 * MC: O(logn)
 * where n denotes upper limit of number
 */
class Solution
{
public:
    int firstBadVersion(int n, int l = 0, int version = -1)
    {
        int mid = l + ((n - l) / 2);
        if (l >= n)
        {
            version = min(l, n);
            return version;
        }
        if (isBadVersion(mid))
        {
            version = mid;
            return firstBadVersion(mid, l, version);
        }
        else
            return firstBadVersion(n, mid + 1, version);
    }
};