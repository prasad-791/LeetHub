class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<char,int> mp;
        vector<string> ans;
        for(int i=0;i<words2.size();i++){
            map<char,int> mp1;
            for(auto& ch:words2[i]){
                mp1[ch]++;
            }
            for(auto& it:mp1){
                if(mp[it.first] < it.second){
                    mp[it.first] = it.second;
                }
            }
        }
        for(int i=0;i<words1.size();i++){
            map<char,int> mp1;
            for(auto& ch:words1[i]){
                mp1[ch]++;
            }
            bool flag = true;
            for(auto& it:mp){
                if(mp1[it.first] < it.second){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};