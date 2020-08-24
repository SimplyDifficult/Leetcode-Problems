class Solution {
public:
    vector<vector<int>>ans;
    vector<int>curr;
    int k;
    
    void f(vector<int>nums,int start){
        if(curr.size()==k){
            ans.push_back(curr);
            return;
        }
        for(int i=start;i<nums.size();i++){
            curr.push_back(nums[i]);
            f(nums,i+1);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        for(k=0;k<=nums.size();k++){
            f(nums,0);
        }
        return ans;
    }
};
