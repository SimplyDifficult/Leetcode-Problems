class Solution {
public:
    
    static bool compare(vector<int>a,vector<int>b){
        return a[1]<b[1];
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>>jobs;
        
        for(int i=0;i<n;i++){
        	jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end(),compare);
        vector<int>dp(n,0);

        for(int i=0;i<n;i++){
        	if(!i){dp[i]=jobs[i][2];continue;}
        	int curr=0;
        	for(int j=i-1;j>=0;j--){
        		if(jobs[j][1]<=jobs[i][0]){
        			curr=dp[j];break;
        		}
        	}
        	dp[i]=max(dp[i-1],curr+jobs[i][2]);
        }
        return dp[n-1];
    }
};
