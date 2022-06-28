class Solution {
public:
    int minDeletions(string s) {
        sort(s.begin(),s.end());
        map<int,int> mp;
        char ch = s[0];
        int cnt =0;
        int ans = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]==ch){
                cnt++;
            }else{
                int x = cnt;
                while(mp.count(cnt)!=0 && cnt!=0){
                    cnt--;
                }
                ans += (x-cnt);
                mp[cnt]=1;
                ch = s[i];
                cnt=1;
            }
        }
        int x = cnt;
        while(mp.count(cnt)!=0 && cnt!=0){
            cnt--;
        }
        ans += (x-cnt);
        return ans;
    }
};