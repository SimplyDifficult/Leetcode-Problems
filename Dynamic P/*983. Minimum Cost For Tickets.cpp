class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        set<int>set;
        for(int i=0;i<days.size();i++)set.insert(days[i]);
        vector<int>dp(366);
        dp[0]=0;
        for(int i=1;i<=365;i++){
            if(set.find(i)==set.end())dp[i]=dp[i-1];
            else dp[i]=min(dp[max(0,i-1)]+costs[0],min(dp[max(0,i-7)]+costs[1],dp[max(0,i-30)]+costs[2]));
        }
        return dp[365];
    }
};
