# Approach 1
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        for(auto x:nums)
        {
            if(x!=0)
                nums[index++] = x;
        }
        for(int i=index;i<n;i++)
            nums[i]=0;
    }
};

