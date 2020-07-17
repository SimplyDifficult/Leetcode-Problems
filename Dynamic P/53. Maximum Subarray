class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>0)nums[i]+=nums[i-1];
            maxsum=max(maxsum,nums[i]);
        }
        return maxsum;
    }
};
