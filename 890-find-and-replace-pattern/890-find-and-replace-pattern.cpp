class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = pattern.length();
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            if(words[i].length()>n){
                continue;
            }
            map<char,char> mp;
            map<char,char> mp1;
            int j=0;
            string w = words[i];
            while(j<n){
                if(mp.count(pattern[j])==0 && mp1.count(w[j])==0){
                    mp[pattern[j]] = w[j];
                    mp1[w[j]] = pattern[j];
                }else if(mp[pattern[j]]!=w[j] || mp1[w[j]]!=pattern[j]){
                    break;
                }
                j++;
            }
            if(j==n){
                ans.push_back(w);
            }
        }
        return ans;
    }
};