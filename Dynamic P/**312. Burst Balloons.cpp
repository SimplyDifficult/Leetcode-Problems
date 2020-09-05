class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int i=0;i<n;i++){
            for(int l=1;l<=n-i;l++){
                int r=l+i;
                for(int k=l;k<=r;k++){
                    dp[l][r]=max(dp[l][r],dp[l][k-1]+dp[k+1][r]+nums[l-1]*nums[k]*nums[r+1]);
                }
            }
        }
        return dp[1][n];
    }
};
