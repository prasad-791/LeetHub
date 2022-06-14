class Solution {
public:
    vector<vector<int>> dp;
    int help(string s1, string s2, int i, int j){
        if(i==s1.length() || j==s2.length()){
            return 0;
        }
        if(dp[i][j] >= 0){
            return dp[i][j];
        }
        if(s1[i] == s2[j]){
            dp[i][j] = 1 + help(s1,s2,i+1,j+1);
        }else{
            dp[i][j] = max(help(s1,s2,i+1,j),help(s1,s2,i,j+1));
        }
        return dp[i][j];
    }
    // int longestCommonSubsequence(string text1, string text2) {
    //     dp = vector<vector<int>>(text1.length(),vector<int>(text2.length(),-1));
    //     return help(text1,text2,0,0);
    // }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,0));
        for(int i=1;i<=text1.length();i++){
            for(int j=1;j<=text2.length();j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[text1.length()][text2.length()];
    }
};