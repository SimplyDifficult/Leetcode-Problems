class Solution {
public:
    int numSquares(int n) {
        int N=sqrt(n)+1;
        vector<int>sq(N+1);
        for(int i=0;i<=N;i++){
            sq[i]=i*i;
        }
        vector<int>dp(n+1,n+1);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<sq.size();j++){
                if(sq[j]<=i)dp[i]=min(dp[i],dp[i-sq[j]]+1);
            }
        }
        return dp[n];
    }
};
