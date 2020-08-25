class Solution {
public:
    int uniquePaths(int m, int n) {
        int map[100][100]={0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0)map[i][j]=1;
                else if(j==0)map[i][j]=1;
                else map[i][j]=map[i-1][j]+map[i][j-1];
            }
        }
        return map[m-1][n-1];
    }
};
