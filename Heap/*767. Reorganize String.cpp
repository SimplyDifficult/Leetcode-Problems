class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        
        vector<int>cnt(26);
        for(auto c:s){
            cnt[c-'a']++;
        }
        
        priority_queue<pair<int,char>>pq;
        
        for(int i=0;i<26;i++){
            if(cnt[i]>(n+1)/2)return "";
            if(cnt[i])pq.push({cnt[i],i+'a'});
        }
        queue<pair<int,char>>q;
        string ans;
        
        while(!pq.empty() || q.size()>1){
            if(q.size()>1){
                auto curr=q.front();q.pop();
                if(curr.first!=0)pq.push(curr);
            }
            if(!pq.empty()){
                auto curr=pq.top();pq.pop();
                ans+=curr.second;
                curr.first--;
                q.push(curr);
            }
        }
        return ans;
        
    }
};
