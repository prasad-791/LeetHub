class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j){
        int m = board.size();
        int n = board[0].size();
        if(i==-1 || i==m || j==-1 || j==n || board[i][j]!='O'){
            return ;
        }
        board[i][j] = '#';
        dfs(board,i+1,j);
        dfs(board,i-1,j);
        dfs(board,i,j+1);
        dfs(board,i,j-1);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                dfs(board,0,i);
            }
        }
        for(int i=0;i<n;i++){
            if(board[m-1][i]=='O'){
                dfs(board,m-1,i);
            }
        }
        for(int i=1;i<m-1;i++){
            if(board[i][0]=='O'){
                dfs(board,i,0);
            }
        }
        for(int i=1;i<m-1;i++){
            if(board[i][n-1]=='O'){
                dfs(board,i,n-1);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='#'){
                    board[i][j] = 'O';
                }else if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};