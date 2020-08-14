class Solution {
public:
    
    static bool compare(vector<int>a,vector<int>b){
        return a[0]<b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        if(intervals.size()==0)return ans;
        sort(intervals.begin(),intervals.end(),compare);
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(ans.back()[1]>=intervals[i][0])ans.back()[1]=max(intervals[i][1],ans.back()[1]);
            else ans.push_back(intervals[i]);
        }
        return ans;
    }
};
