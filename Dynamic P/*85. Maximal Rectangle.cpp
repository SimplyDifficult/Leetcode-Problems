class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())return 0;
        int n=matrix.size(),m=matrix[0].size();
        vector<int>h(m,0),l(m,0),r(m,m-1);
        int ans=0;
        for(int i=0;i<n;i++){
            int L=0,R=m-1;
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')l[j]=max(l[j],L);
                else{
                    l[j]=0;
                    L=j+1;
                }
                if(matrix[i][j]=='1')h[j]++;
                else h[j]=0;
            }
            for(int j=m-1;j>=0;j--){
                if(matrix[i][j]=='1')r[j]=min(r[j],R);
                else{
                    r[j]=m-1;
                    R=j-1;
                }
            }
            for(int j=0;j<m;j++){
                int curr=(r[j]-l[j]+1)*h[j];
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};
