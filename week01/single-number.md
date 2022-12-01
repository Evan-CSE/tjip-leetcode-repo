# Approach 1
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0],len=nums.size();
        for(int i=1;i<len;i++)ans^=nums[i];
        return ans;
        
    }
};