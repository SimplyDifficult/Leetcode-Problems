class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int dp[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=0;
            }
        }
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if((j-i<3 || dp[i+1][j-1]) && s[i]==s[j]){
                    dp[i][j]=1;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
