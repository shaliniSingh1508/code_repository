class Solution {
public:
    bool comb(int x,int y,int index,string s,vector<vector<char>>& board){
        if(index==s.size()-1){
            return true;
        }
        char ch=board[x][y];
        board[x][y]='0';

        int d[][2]={{1,0},{-1,0},{0,1},{0,-1}};

        for(int i=0; i<4; i++){
            int dx=x+d[i][0];
            int dy=y+d[i][1];

            if(dx>=0 and dx<board.size() and dy>=0 and dy<board[0].size() and s[index+1]==board[dx][dy]){
                if(comb(dx,dy,index+1,s,board))
                    return true;
            }
        }
        board[x][y]=ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty())
            return false;
        int n=board.size();
        int m=board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==word[0])
                {
                    if(comb(i,j,0,word,board))
                        return true;
                }
            }
        }
        return false;

    }
};