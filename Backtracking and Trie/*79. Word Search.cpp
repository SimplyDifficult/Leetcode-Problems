class Solution {
public:
    int n,m;
    
    bool dfs(vector<vector<char>>& board,string word,int i,int j,int k){
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!=word[k])return false;
        if(k==word.size()-1)return true;
        
        char curr=board[i][j];
        board[i][j]='*';
        bool next=dfs(board,word,i+1,j,k+1)||
            dfs(board,word,i-1,j,k+1)||
            dfs(board,word,i,j+1,k+1)||
            dfs(board,word,i,j-1,k+1);
        board[i][j]=curr;
        return next;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty())return true;
        n=board.size();
        if(n==0)return false;
        m=board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(board,word,i,j,0))return true;
            }
        }
        return false;
    }
};
