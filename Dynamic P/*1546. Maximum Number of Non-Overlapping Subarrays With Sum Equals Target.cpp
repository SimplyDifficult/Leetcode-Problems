class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0,ans=0;
        map<int,int>mp;
        mp[0]=0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mp.find(sum-target)!=mp.end())ans=max(ans,mp[sum-target]+1);
            mp[sum]=ans;
        }
        return ans;
    }
};
