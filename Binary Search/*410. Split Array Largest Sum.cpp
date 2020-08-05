#define ll long long
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        ll maxi=0,sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxi=max(maxi,(ll)nums[i]);
        }
        ll l=maxi,r=sum;
        ll ans;
        
        while(l<=r){
            ll mid=l+(r-l)/2;
            ll curr=0,cnt=1;
            for(int i=0;i<nums.size();i++){
                if(curr+nums[i]<=mid){
                    curr+=nums[i];
                }
                else{
                    curr=nums[i];
                    cnt++;
                }
            }
            if(cnt<=m){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
