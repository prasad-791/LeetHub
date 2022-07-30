class Solution {
public:
    int m,n;
    bool dfs(vector<vector<int>>& grid,int i,int j){
        if(grid[i][j]==1 || grid[i][j]==-1){
            return true;
        }
        if(i<=0 || j<=0 || i==m-1 || j==n-1){
            return false;
        }
        grid[i][j] = -1;
        bool q1 = dfs(grid,i-1,j);
        bool q2 = dfs(grid,i+1,j);
        bool q3 = dfs(grid,i,j+1);
        bool q4 = dfs(grid,i,j-1);
        return q1 && q2 && q3 && q4;
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
    
        int count = 0;
        
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==0){
                    if(dfs(grid,i,j)){
                        count++;
                    }          
                }
            }
        }
        return count;
    }
};