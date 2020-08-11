class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[coins.size()+1][amount+1];
        for(int i=0;i<=coins.size();i++){
            for(int j=0;j<=amount;j++)dp[i][j]=0;
        }
        dp[0][0]=1;
        for(int i=1;i<=coins.size();i++){
            dp[i][0]=1;
            for(int j=1;j<=amount;j++){
                if(coins[i-1]>j)dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
            }
        }
        return dp[coins.size()][amount];
    }
};

/*class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int ans=0;
        vector<int>dp(amount+1,0);
        dp[0]=1;
        for(int i=0;i<coins.size();i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j]+=dp[j-coins[i]];
            } 
        }
        return dp[amount];
    }
};
