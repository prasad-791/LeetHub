class Solution {
public:
    vector<int> partitionLabels(string s) {
        queue<char> q;
        vector<int> f(26,0);
        map<int,int> mp;
        
        for(auto& ch:s){
            f[ch-'a']++;
        }
        q.push(s[0]);
        mp[s[0]]=1;
        vector<int> ans;
        int count =0, i=0;
        while(!q.empty() && i<s.length()){
            f[s[i]-'a']--;
            if(f[q.front()-'a']==0){
                q.pop();
                if(q.empty() && i<s.length()){
                    // cout<<"H "<<i<<endl;
                    ans.push_back(count+1);
                    count = 0;
                    i++;
                    mp[s[i]] = 1;
                    q.push(s[i]);
                }
            }else{
                if(mp.count(s[i])==0){
                    mp[s[i]]=1;
                    q.push(s[i]);
                }
                count++;
                i++;
            }
        }
        
        return ans;
    }
};