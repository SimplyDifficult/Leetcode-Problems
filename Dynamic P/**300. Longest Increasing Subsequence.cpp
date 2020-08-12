class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        vector<int>dp(n,1);
        int ans=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i])dp[i]=max(dp[i],1+dp[j]);
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};

/*class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int len=0;
        vector<int>arr(n+1,0);
        for(int i=0;i<n;i++){
            int l=0,r=len;
            while(l<r){
                int mid=(l+r)/2;
                if(arr[mid]>=nums[i])r=mid;
                else l=mid+1;
            }
            arr[l]=nums[i];
            if(l==len)len++;
        }
        return len;
    }
};
