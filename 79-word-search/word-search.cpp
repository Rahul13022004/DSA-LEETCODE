class Solution {
public:
    bool solve(int i,int j,int idx,int m,int n,string word,vector<vector<char>>&board){
        if(idx==word.length())return true;
        if(i<0 || i>=m || j<0|| j>=n|| board[i][j]=='!'||board[i][j]!=word[idx])return false;
        char ch=board[i][j];
        board[i][j]='!';
        bool top=solve(i-1,j,idx+1,m,n,word,board);
        bool down=solve(i+1,j,idx+1,m,n,word,board);
        bool left=solve(i,j-1,idx+1,m,n,word,board);
        bool right=solve(i,j+1,idx+1,m,n,word,board);
        board[i][j]=ch;
        return top||down||left||right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        int idx=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[idx]){
                    if(solve(i,j,idx,m,n,word,board))return true;
                }
            }
        }
        return false;
    }
};