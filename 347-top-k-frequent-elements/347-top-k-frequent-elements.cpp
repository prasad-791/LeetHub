class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto& i:nums){
            mp[i]++;
        }
        map<int,vector<int>> mp1;
        for(auto& it:mp){
            mp1[it.second].push_back(it.first);
        }
        vector<int> temp;
        for(auto& it:mp1){
            for(auto& i:it.second){
                temp.push_back(i);
            }
        }
        vector<int> ans;
        for(int i=temp.size()-1;i>=0 && k>0;i--){
            ans.push_back(temp[i]);
            k--;
        }
        return ans;
    }
};