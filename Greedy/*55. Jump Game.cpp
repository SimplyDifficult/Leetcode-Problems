class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxpos=nums[0];
        for(int i=1;i<n;i++){
            if(maxpos<i)return false;
            maxpos=max(maxpos,i+nums[i]);
        }
        return true;
    }
};
