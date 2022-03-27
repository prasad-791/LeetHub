class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int,vector<int>>mp;
        int n = mat.size(), m = mat[0].size();
        for(int i=0;i<n;i++){
            int count =0 ;
            for(int j=0;j<m && mat[i][j]==1;j++){
                count++;
            }
            mp[count].push_back(i);
        }
        
        vector<int> ans;
        for(auto& it:mp){
            vector<int> temp = it.second;
            for(auto &i:temp){
                ans.push_back(i);
                k--;
                if(k==0) break;
            }
            if(k==0) break;
        }
        return ans;
    }
};