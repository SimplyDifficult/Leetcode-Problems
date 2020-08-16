class Solution {
public:
    map<string,multiset<string>>mp;
    vector<string>ans;
    
    void dfs(string airport){
        while(mp[airport].size()){
            string next=*mp[airport].begin();
            mp[airport].erase(mp[airport].begin());
            dfs(next);
        }
        ans.push_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto t:tickets){
            mp[t[0]].insert(t[1]);
        }
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
