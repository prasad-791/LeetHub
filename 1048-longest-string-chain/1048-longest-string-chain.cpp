class Solution {
public:
    vector<int> dp;
    static bool cmp(string a, string b){
        if(a.length()==b.length()){
            return a<b;
        }
        return a.length()<b.length();
    }
    int help(vector<string>& w, int i,vector<int>& visited){
        visited[i]=1;
        if(i==0){
            return dp[i]=1;
        }
        if(dp[i]!=0){
            return dp[i];
        }
        int j=i-1;
        while(j>=0 && w[j].length()==w[i].length()){
            j--;
        }
        int ans = 1;
        while(j>=0){
            if(isSubSeq(w[j],w[i]) && w[i].length()-w[j].length()==1){
                // cout<<w[j]<<" "<<w[i]<<endl;
                ans = max(ans,1 + help(w,j,visited));
            }
            j--;
        }
        return dp[i]=ans;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        vector<int> visited(words.size(),0);
        dp = vector<int>(words.size(),0);
        // int ans =INT_MIN;
        for(int i=words.size()-1;i>=0;i--){
            if(visited[i]==0){
                help(words,i,visited);   
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
    bool isSubSeq(string s1, string s2){
        int i=0, j=0;
        while(i<s1.length() && j<s2.length()){
            if(s1[i]==s2[j]){
                i++;
            }
            j++;
        }
        return i == s1.length();
    }
};