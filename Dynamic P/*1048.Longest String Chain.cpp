class Solution {
public:
    
    static bool compare(string a, string b){
        return a.size()<b.size();
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        unordered_map<string,int>dp;
        int ans=0;
        
        for(string w:words){
            for(int i=0;i<w.size();i++){
                dp[w]=max(dp[w],dp[w.substr(0,i)+w.substr(i+1)]+1);
            }
            ans=max(ans,dp[w]);
        }
        return ans;
    }
};
