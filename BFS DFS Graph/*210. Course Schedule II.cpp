class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n,vector<int>());
        vector<int>degree(n,0);
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
            degree[i[0]]++;
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(degree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ans.push_back(u);
            n--;
            for(auto v:adj[u]){
                degree[v]--;
                if(degree[v]==0)q.push(v);
            }
        }
        if(n==0)return ans;
        return vector<int>();
    }
};
