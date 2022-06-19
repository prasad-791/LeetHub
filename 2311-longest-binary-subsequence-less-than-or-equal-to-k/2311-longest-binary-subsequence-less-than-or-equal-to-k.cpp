class Solution {
public:
    int longestSubsequence(string s, int k) {
        reverse(s.begin(),s.end());
        long long int ind = 0, val = 0,ans=0;
        int i=0;
        while(i<s.length() && val+pow(2,ind)<=k){
            long long temp = (s[i]-'0');
            val += pow(2,ind)*temp;
            ind++;
            ans++;
            i++;
        }
        while(i<s.length()){
            if(s[i]=='0'){
                ans++;
            }
            i++;
        }
        return ans;
    }
};