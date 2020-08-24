class Solution {
public:
    vector<vector<int>>ans;
    
    void f(vector<int>num,int start){
        if(start==num.size()-1){
            ans.push_back(num);
            return;
        }
        for(int i=start;i<num.size();i++){
            swap(num[start],num[i]);
            f(num,start+1);
            swap(num[start],num[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        f(nums,0);
        return ans;
    }
};
