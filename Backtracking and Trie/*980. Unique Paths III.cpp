class Solution {
public:
    int n,m;
    
    int dfs(vector<vector<int>>grid,int i,int j){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==-1)return 0;
        
        if(grid[i][j]==2){
            for(int x=0;x<n;x++){
                for(int y=0;y<m;y++){
                    if(grid[x][y]==0)return 0;
                }
            }
            return 1;
        }
        
        int temp=grid[i][j];
        grid[i][j]=-1;
        int res=dfs(grid,i-1,j)+dfs(grid,i+1,j)+dfs(grid,i,j+1)+dfs(grid,i,j-1);
        grid[i][j]=temp;
        
        return res;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    return dfs(grid,i,j);
            }
        }
        return 0;
    }
};
