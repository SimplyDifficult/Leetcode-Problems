class Solution {
public:
    
    static bool compare(vector<int>a,vector<int>b){
        return a[0]<b[0];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty())return 0;
        sort(intervals.begin(),intervals.end(),compare);
        int end=intervals[0][1];
        int count=1;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=end){
                end=intervals[i][1];
                count++;
            }
            else{
                end=min(end,intervals[i][1]);
            }
        }
        return intervals.size()-count;
    }
};
