class Solution {
public:
    
    bool isSafe(int row,int col, vector<vector<char>>&board,char num){
        for(int j=0;j<9;j++){
            if(board[row][j]==num)  return false;
        }
        for(int i=0;i<9;i++){
            if(board[i][col]==num)  return false;
        }
        int down=row/3;
        int right=col/3;
        for(int i=down*3;i<(down*3+3);i++){
            for(int j=right*3;j<(right*3+3);j++){
                if(board[i][j]==num)    return false;
            }
        }
        return true;
    }
    
    void solve(int row,int col,vector<vector<char>>& board,bool &flag){
        if(row==9){
            flag=true;
            return;
        }
        if(col==9) {
            solve( row+1, 0,board,flag);
            return;
        }
        if(board[row][col] != '.')  {
            solve( row, col+1,board,flag);
            return;
        }

        for(char c='1'; c<='9'; c++)
        {
            if(isSafe(row, col, board, c))
            {
                board[row][col] = c;
                solve( row, col+1,board,flag);
                if(flag==true)  return;
                else board[row][col] = '.';
            }
        }
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        bool flag=false;
        solve(0,0,board,flag);
    }
};