class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        if(n==0)return 0;
        int m=obstacleGrid[0].size();

        if(obstacleGrid[0][0]==1)return 0;

        obstacleGrid[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j!=0){
                    if(obstacleGrid[i][j]==1)obstacleGrid[i][j]=0;
                    else obstacleGrid[i][j]=obstacleGrid[i][j-1];
                }
                else if(j==0 && i!=0){
                    if(obstacleGrid[i][j]==1)obstacleGrid[i][j]=0;
                    else obstacleGrid[i][j]=obstacleGrid[i-1][j];
                }
                else if(i!=0 && j!=0){
                    if(obstacleGrid[i][j]==1)obstacleGrid[i][j]=0;
                    else obstacleGrid[i][j]=obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
                }
            }
        }
        return obstacleGrid[n-1][m-1];
    }
};
