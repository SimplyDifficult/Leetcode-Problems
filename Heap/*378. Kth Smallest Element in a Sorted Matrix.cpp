class Solution {
public:
    struct compare{
        bool operator()(pair<int,pair<int,int>>a,pair<int,pair<int,int>>b){
            return a.first>b.first;
        }
    };
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size(),m=matrix[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,compare>p;
        for(int i=0;i<n;i++){
            p.push({matrix[i][0],{i,0}});
        }
        int ans;
        while(k--){
            int val=p.top().first;
            int row=p.top().second.first;
            int col=p.top().second.second;
            ans=val;
            p.pop();
            if(col!=m-1){
                p.push({matrix[row][col+1],{row,col+1}});
            }
        }
        return ans;
    }
};

/*expected ';' after struct*/
