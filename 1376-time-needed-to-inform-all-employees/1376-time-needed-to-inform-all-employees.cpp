class Solution {
public:
    int dfs(vector<vector<int>>& adj, vector<int>& infoT, int curr){
        int time = 0;
        for(int i=0;i<adj[curr].size();i++){
            time = max(time,infoT[curr]+dfs(adj,infoT,adj[curr][i]));
        }
        return time;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }
        return dfs(adj,informTime,headID);
    }
};