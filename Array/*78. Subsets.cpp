class Solution {
public:
    
    vector<vector<int>>ans;
    int k,n;
    
    void f(vector<int>nums,int first,vector<int>curr){
        if(curr.size()==k){
            ans.push_back(curr);
            return;
        }
        
        for(int i=first;i<n;i++){
            curr.push_back(nums[i]);
            f(nums,i+1,curr);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        vector<int>curr;
        
        for(k=0;k<=n;k++){
            f(nums,0,curr);
        }
        return ans;
    }
};
