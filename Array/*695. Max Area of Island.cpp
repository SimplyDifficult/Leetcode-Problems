class Solution {
public:
    
    int f(vector<vector<int>>&grid,int r,int c){
        if(r<0||c<0||r>=grid.size()||c>=grid[0].size()||grid[r][c]==0)return 0;
        grid[r][c]=0;
        return 1+f(grid,r-1,c)+f(grid,r+1,c)+f(grid,r,c-1)+f(grid,r,c+1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int A=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    A=max(A,f(grid,i,j));
                }
            }
        }
        return A;
    }
};

/*class Solution {
public:
    
    int dfs(vector<vector<int>>& grid,int i,int j){
    	int curr=0,n=grid.size(),m=grid[0].size();
        if(grid[i][j]==0)return;
        grid[i][j]=0;
        curr++;
        if(i>0 && grid[i-1][j]==1)curr+=dfs(grid,i-1,j);
        if(i<n-1 && grid[i+1][j]==1)curr+=dfs(grid,i+1,j);
        if(j>0 && grid[i][j-1]==1)curr+=dfs(grid,i,j-1);
        if(j<m-1 && grid[i][j+1]==1)curr+=dfs(grid,i,j+1);
        return curr;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    	int curr,ans=0;
        for(int i=0;i<grid.size();i++){
        	for(int j=0;j<grid[0].size();j++){
        		if(grid[i][j]==1)curr=dfs(grid,i,j);
        	}
        	ans=max(ans,curr);
        }
        return ans;
    }
};*/
