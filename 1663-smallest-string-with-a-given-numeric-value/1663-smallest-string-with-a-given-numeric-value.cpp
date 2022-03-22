class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        
        int last = 26;
        while(k < (last+n-1)){
            last--;
        }
        ans += (last-1)+'a';
        n--;
        k -= last;
        
        while(k>last && k>last+n-1){
            ans += (last-1)+'a';
            k-=last;
            n--;
        }
        int x = k-n+1;
        ans += x-1 + 'a';
        n--;
        while(n--){
            ans += 'a';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};