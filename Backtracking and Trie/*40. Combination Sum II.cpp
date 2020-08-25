class Solution {
public:
    vector<vector<int>>ans;
    vector<int>curr;
    
    void f(vector<int>& candidates,int first,int target){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        for(int i=first;i<candidates.size();i++){
            if(i>first && candidates[i]==candidates[i-1])continue;
            if(candidates[i]<=target){
                curr.push_back(candidates[i]);
                f(candidates,i+1,target-candidates[i]);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        f(candidates,0,target);
        return ans;
    }
};
