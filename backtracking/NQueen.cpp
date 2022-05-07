class Solution {
public:
    bool isSafe(int col,int row,vector<string> &board,int n){
        int duprow=row;
        int dupcol=col;

        while(row>=0 and col>=0){
            if(board[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        row=duprow;
        col=dupcol;
        while(col>=0){
            if(board[row][col]=='Q')
                return false;
            col--;
        }
       row=duprow;
       col=dupcol;
       while(row<n and col>=0){
           if(board[row][col]=='Q')
                return false;
           row++;
           col--;
       }
       return true;
    }
    void solve(int col,vector<string> &board,vector<vector<string>> &res,int n){
        if(col==n){
            res.push_back(board);
            return;
        }
        for(int row=0; row<n; row++){
            if(isSafe(col,row,board,n)){
                board[row][col]='Q';
                solve(col+1,board,res,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);

        string s(n,'.');
        for(int i=0; i<n; i++)
            board[i]=s;
        solve(0,board,res,n);
        return res;

    }
};