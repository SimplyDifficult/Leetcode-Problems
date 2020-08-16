class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n,vector<int>());
        vector<int>degree(n,0);
        for(auto i:prerequisites){
        	adj[i[1]].push_back(i[0]);
        	degree[i[0]]++;
        }
        queue<int>q;

        for(int i=0;i<n;i++){
        	if(degree[i]==0)q.push(i);
        }
        while(!q.empty()){
        	int curr=q.front();
        	q.pop();
        	n--;
        	for(auto v:adj[curr]){
        		degree[v]--;
        		if(degree[v]==0)q.push(v);
        	}
        }
        return n==0;
    }
};
