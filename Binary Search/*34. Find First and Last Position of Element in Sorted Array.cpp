class Solution {
public:
    
    int lower_bound(vector<int>nums,int target){
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]<target)l=mid+1;
            else r=mid-1;
        }
        return l;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int a=lower_bound(nums,target);
        int b=lower_bound(nums,target+1)-1;
        if(a<nums.size() && nums[a]==target)return {a,b};
        return {-1,-1};
    }
};
