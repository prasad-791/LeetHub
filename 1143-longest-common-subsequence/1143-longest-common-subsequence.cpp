class Solution {
public:
    vector<vector<int>> dp;
    int solve(string s, string t, int i, int j){
        if(i==-1 || j==-1){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j] = 1 + solve(s,t,i-1,j-1);
        }
        int lf = solve(s,t,i-1,j);
        int ls = solve(s,t,i,j-1);
        return dp[i][j] = max(lf,ls);
    }
    int longestCommonSubsequence(string s, string t) {
        // dp = vector<vector<int>>(s.length()+1,vector<int>(t.length()+1,-1));
        // return solve(s,t,s.length()-1,t.length()-1);
        
        dp = vector<vector<int>>(s.length()+1,vector<int>(t.length()+1,0));
        
        int n = s.length(), m = t.length();
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    }
};