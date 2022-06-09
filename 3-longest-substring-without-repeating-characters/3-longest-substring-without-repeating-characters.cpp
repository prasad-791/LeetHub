class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(256,0);  // store the frequency of each character
        int ans = 0, l=0,r=0;   
        while(r<s.length()){    // till the pointer reaches end of string
            mp[s[r]]++;     // increment the freq of newest character
            while(mp[s[r]] > 1){    // until any duplicate is present in the string
                // remove characters from left pointer as the duplicate may be present somewhere                in the middle of the string
                mp[s[l]]--;
                l++;
            }
            // update ans if necessary
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};