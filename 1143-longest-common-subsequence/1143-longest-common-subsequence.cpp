class Solution {
public:
    // try to express in terms of index
    // explore possibility of that index
    // take the best among them
    
    // Here as there are two strings we need two indices 
    // f(1,3) means the answer for string1(0...1) and string2(0...3)
    
    int onlyRec(string s1, string s2, int i, int j){
        if(i==-1 || j==-1){
            return 0;
        }
        // now we will check if the character at i and j matches
        // if it matches then we would include it in answer and check for i-1 and j-1
        if(s1[i] == s2[j]){
            return 1 + onlyRec(s1,s2,i-1,j-1);
        }
        // if it doesn't matches then we have 2 possibilites:
        // i-1,j and i,j-1
        // aec and ace
        return max(onlyRec(s1,s2,i-1,j),onlyRec(s1,s2,i,j-1));
    }
    
    vector<vector<int>> dp; // 2D for both strings
    int memo(string s1, string s2, int i, int j){
        if(i==-1 || j==-1){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // now we will check if the character at i and j matches
        // if it matches then we would include it in answer and check for i-1 and j-1
        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + memo(s1,s2,i-1,j-1);
        }
        // if it doesn't matches then we have 2 possibilites:
        // i-1,j and i,j-1
        // aec and ace
        return dp[i][j] = max(memo(s1,s2,i-1,j),memo(s1,s2,i,j-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        // start from last index of both string
        // return onlyRec(text1,text2,text1.length()-1,text2.length()-1);
    
        // dp = vector<vector<int>>(text1.length(),vector<int>(text2.length(),-1));
        // return memo(text1,text2,text1.length()-1,text2.length()-1);
        
        vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,0));
        for(int i=1;i<=text1.length();i++){
            for(int j=1;j<=text2.length();j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[text1.length()][text2.length()];
    }
};