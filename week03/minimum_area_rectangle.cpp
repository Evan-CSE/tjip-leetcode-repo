// TC: O(n*n)
// MC: O(n)
// where n denotes number of points

class Solution
{
public:
    const static int BASE = (5e4) + 2;
    int minAreaRect(vector<vector<int>> &points)
    {
        int x, y, x3, y3, minArea = INT_MAX, area;
        unordered_map<int, int> pair_count;
        for (auto &x : points)
            pair_count[x[0] * BASE + x[1]]++;
        for (auto &point : points)
        {
            x = point[0];
            y = point[1];
            for (auto &point_3 : points)
            {
                x3 = point_3[0];
                y3 = point_3[1];
                if (x == x3 && y3 == y)
                    continue;
                area = abs(x - x3) * abs(y - y3);
                if (area > 0 && pair_count.count(x * BASE + y3) && pair_count.count(x3 * BASE + y))
                    minArea = min(minArea, area);
            }
        }
        return minArea == INT_MAX ? 0 : minArea;
    }
};