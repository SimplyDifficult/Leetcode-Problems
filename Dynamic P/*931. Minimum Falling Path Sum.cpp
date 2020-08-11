class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n=A.size();
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int best=A[i+1][j];
                if(j>0)best=min(best,A[i+1][j-1]);
                if(j<n-1)best=min(best,A[i+1][j+1]);
                A[i][j]+=best;
            }
        }
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            ans=min(ans,A[0][j]);
        }
        return ans;
    }
};
