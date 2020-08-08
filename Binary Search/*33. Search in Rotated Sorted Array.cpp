class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)return -1;
        int l=0,r=nums.size()-1;
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]>nums[r]){
                if(nums[mid]<target || target<=nums[r])l=mid+1;
                else r=mid;
            }
            else{
                if(target>nums[mid] && target<=nums[r])l=mid+1;
                else r=mid;
            }
        }
        if(l==r && nums[l]!=target)return -1;
        return l;
    }
};
