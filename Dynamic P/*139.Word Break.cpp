class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string>word;
        for(int i=0;i<wordDict.size();i++)word.insert(wordDict[i]);
        vector<int>dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=i;j++){
                if(dp[j]){
                    string curr=s.substr(j,i-j);
                    if(word.find(curr)!=word.end()){
                        dp[i]=1;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};
