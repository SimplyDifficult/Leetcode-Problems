class Solution {
public:

    bool f(vector<int>&nums, int k, vector<bool>&visited, int cur_idx,int cur_sum,int target){
        if(k==0)return true;

        if(cur_sum==target)return f(nums,k-1,visited,0,0,target);

        for(int i=cur_idx;i<nums.size();i++){
            if(!visited[i] && cur_sum+nums[i]<=target){
                visited[i]=true;
                if(f(nums,k,visited,i+1,cur_sum+nums[i],target))return true;
                visited[i]=false;
            }
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%k!=0 || k<=0)return false;

        int target=(sum/k);
        vector<bool>visited(nums.size(),0);
        return f(nums,k,visited,0,0,target);
    }
};
