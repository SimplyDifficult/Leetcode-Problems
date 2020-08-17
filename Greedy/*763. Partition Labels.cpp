class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int>last(26);
        for(int i=0;i<S.size();i++)last[S[i]-'a']=i;
        vector<int>ans;
        int prev=0;
        int currmax=0;
        for(int i=0;i<S.size();i++){
            currmax=max(currmax,last[S[i]-'a']);
            if(i==currmax){
                ans.push_back(i-prev+1);
                currmax=i+1;
                prev=i+1;
            }
        }
        return ans;
    }
};
