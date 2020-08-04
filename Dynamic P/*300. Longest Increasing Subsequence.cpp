class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size());
        int len=0;
        for(auto x:nums){
            int left=0,right=len;
            while(left!=right){
                int mid=(left+right)/2;
                if(dp[mid]<x)left=mid+1;
                else right=mid;
            }
            dp[left]=x;
            if(left==len)len++;
        }
        return len;
    }
};
