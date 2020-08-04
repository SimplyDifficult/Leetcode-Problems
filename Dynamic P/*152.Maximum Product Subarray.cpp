class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int mini=nums[0],maxi=nums[0];
        int result=nums[0];
        for(int i=1;i<nums.size();i++){
            int temp_mini=min(nums[i],min(nums[i]*mini,nums[i]*maxi));
            maxi=max(nums[i],max(nums[i]*mini,nums[i]*maxi));   
            mini=temp_mini;
            result=max(result,maxi);
        }
        return result;
    }
};
