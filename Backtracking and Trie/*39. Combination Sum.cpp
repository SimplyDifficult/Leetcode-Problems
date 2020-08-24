class Solution {
public:
    vector<vector<int>>ans;
    vector<int>curr;
    
    void f(vector<int>candidates,int target,int start){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(candidates[i]<=target){
                curr.push_back(candidates[i]);
                f(candidates,target-candidates[i],i);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        f(candidates,target,0);
        return ans;
    }
};
