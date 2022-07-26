class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& a, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        a[i][j] = 1;
        if(j>0 && grid[i][j-1]=='1' && a[i][j-1]==0){
            dfs(grid,a,i,j-1);
        }
        if(i>0 && grid[i-1][j]=='1'&& a[i-1][j]==0){
            dfs(grid,a,i-1,j);
        }
        if(j<n-1 && grid[i][j+1]=='1'&& a[i][j+1]==0){
            dfs(grid,a,i,j+1);
        }
        if(i<m-1 && grid[i+1][j]=='1' && a[i+1][j]==0){
            dfs(grid,a,i+1,j);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<int>> a(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && a[i][j]==0){
                    dfs(grid,a,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};