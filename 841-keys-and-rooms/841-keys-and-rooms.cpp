class Solution {
public:
    void dfs(vector<vector<int>>& adj,int i,vector<int>& visited){
        visited[i] = 1;
        for(int j=0;j<adj[i].size();j++){
            if(visited[adj[i][j]]==0){
                dfs(adj,adj[i][j],visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(),0);
        dfs(rooms,0,visited);
        for(auto& x:visited){
            if(x==0){
                return false;
            }
        }
        return true;
    }
};