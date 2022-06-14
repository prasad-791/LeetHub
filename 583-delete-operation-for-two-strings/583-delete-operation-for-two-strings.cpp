class Solution {
public:
    int lcs(string s1, string s2){
        vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,0));
        for(int i=1;i<=s1.length();i++){
            for(int j=1;j<=s2.length();j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[s1.length()][s2.length()];
    }
    int minDistance(string word1, string word2) {
        int len = lcs(word1,word2);
        return word1.length()+word2.length() - 2 * len;
    }
};