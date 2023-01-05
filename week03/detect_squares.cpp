// TC: O(n) where n denotes number of points
// MC: O(n) where n denotes number of points

class DetectSquares
{
public:
    unordered_map<int, int> points;
    const static int BASE = 20001;
    DetectSquares()
    {
        points.clear();
    }

    void add(vector<int> point)
    {
        // 1 , 4 => 1*10+4
        int cmpct_value = point[0] * BASE + point[1];
        points[cmpct_value]++;
    }

    int count(vector<int> static_point)
    {
        int tot_sqr = 0;
        int x1 = static_point[0], y1 = static_point[1];
        int cmpct_value_1 = x1 * BASE + y1, cmpct_value_2, cmpct_value_3, cmpct_value_4, x, y;
        for (auto &point : points)
        {
            x = point.first / BASE;
            y = point.first % BASE;
            cmpct_value_2 = x1 * BASE + y;
            cmpct_value_3 = x * BASE + y;
            cmpct_value_4 = x * BASE + y1;
            /**
             *  xy1(c4)------x1y1 (c1)
             *         ------
             *          -----
             *  xy(c3)  -----xy1 (c2)
             */
            if (cmpct_value_1 == cmpct_value_3 || (abs(x1 - x) != abs(y1 - y)))
                continue;
            if (points.count(cmpct_value_2) && points.count(cmpct_value_4))
            {
                tot_sqr += points[cmpct_value_2] * points[cmpct_value_3] * points[cmpct_value_4];
            }
        }
        return tot_sqr;
    }
};
