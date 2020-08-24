class Solution {
public:
    bool valid(vector<vector<char>>&board,int row,int col,char c){
        for(int i=0;i<9;i++){
            if(board[i][col]==c)return false;
        }
        for(int j=0;j<9;j++){
            if(board[row][j]==c)return false;
        }
        int x=(row/3)*3,y=(col/3)*3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[x+i][y+j]==c)return false;
            }
        }
        return true;
    }
    
    bool help(vector<vector<char>>&board,int row,int col){
        if(row==9)return true;
        if(col==9)return help(board,row+1,0);
        if(board[row][col]!='.')return help(board,row,col+1);
        for(char c='1';c<='9';c++){
            if(valid(board,row,col,c)){
                board[row][col]=c;
                if(help(board,row,col+1))return true;
                board[row][col]='.';
            }
        }
        return false;
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        help(board,0,0);
    }
};
