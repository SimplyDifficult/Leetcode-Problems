class Solution {
public:
    int jump(vector<int>& nums) {
        int maxi=0,l=0,r=0;
        int cnt=0,n=nums.size();
        while(maxi<n-1){
            cnt++;
            maxi=r+1;
            for(int i=l;i<=r;i++){
                if(i+nums[i]>=n-1)return cnt;
                maxi=max(maxi,i+nums[i]);
            }
            l=r+1;
            r=maxi;
        }
        return cnt;
    }
};
