class Solution {
public:
    bool isSafe(int row,int col,vector<string>&board){
        int i=row,j=col;
        
        while(i>=0 && j>=0){
            if(board[i][j]=='Q')    return false;
            i--;
            j--;
        }
        i=row;
        j=col;
        while(j>=0){
            if(board[i][j]=='Q')    return false;
            j--;
        }
        i=row;
        j=col;
        while(j>=0 && i<board.size()){
            if(board[i][j]=='Q')    return false;
            i++;
            j--;
        }
        return true;
    }
    
    void solve(int col,vector<string>&board, vector<vector<string>>&ans){
        if(col==board.size()){
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<board.size();row++){
            if(isSafe(row,col,board)){
                board[row][col]='Q';
                solve(col+1,board,ans);
                board[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string row="";
        for(int i=0;i<n;i++)    row+='.';
        vector<string> board;
        for(int i=0;i<n;i++)    board.push_back(row);
        vector<vector<string>> ans;
        solve(0,board,ans);
        return ans;
    }
};