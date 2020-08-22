class Solution {
public:

    map<int,vector<string>>dp;

    vector<string> f(int idx,string s, vector<string>dict){
        if(idx==s.size())return {""};
        if(dp.find(idx)!=dp.end())return dp[idx];

        vector<string>ans;

        for(auto w:dict){
            if(s.substr(idx,w.size())==w){
                vector<string>rem=f(idx+w.size(),s,dict);
                for(string S:rem){
                    ans.push_back(w+(S.empty()?"":" ")+S);
                }
            }
        }
        dp[idx]=ans;
        return ans;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        return f(0,s,wordDict);
    }
};
