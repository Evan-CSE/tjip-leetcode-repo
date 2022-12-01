# Approach 1 
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mx = 0, mxProfit = 0, l = prices.size(), mnPrice[l];
        mnPrice[0] = prices[0];
        for (int i = 1; i < l; i++)
        {
            mnPrice[i] = min(prices[i], mnPrice[i - 1]);
        }

        for (int i = 1; i < l; i++)
        {
            mxProfit = max(mxProfit, prices[i] - mnPrice[i - 1]);
        }
        return mxProfit;
    }
};

# Approach 2  
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int l = prices.size();
        vector<int> futurePrice(l);
        int mx = -1;
        for (int i = l - 1; i >= 0; i--)
        {
            futurePrice[i] = max(mx, prices[i]);
            mx = futurePrice[i];
        }
        // for(auto x:futurePrice)cout<<x<<" ";
        // cout<<endl;
        int ans = 0;
        for (int i = 0; i < l - 1; i++)
        {
            ans = max(ans, futurePrice[i] - prices[i]);
        }
        return ans;
    }
};

# Approach 3
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int l = prices.size();
        vector<int> futurePrice(l);
        int mn = prices[0];
        int ans = 0;
        for (int i = 1; i < l; i++)
        {
            ans = max(ans, prices[i] - mn);
            mn = min(mn, prices[i]);
        }
        return ans;
    }
};

# Approach 4
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int l = prices.size();
        vector<int> futurePrice(l);
        int mn = prices[0];
        int ans = 0;
        for (int i = 1; i < l; i++)
        {
            ans = max(ans, prices[i] - mn);
            mn = min(mn, prices[i]);
        }
        return ans;
    }
};