class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        int small = INT_MAX;
        for(auto& x:nums){
            s.insert(x);
            small = min(small,x);
        }
        int ans = INT_MIN;
        int c = 0;
        int prev = small-1;
        for(auto& x:s){
            if(prev+1 == x){
                c++;
            }else{
                ans = max(ans,c);
                c = 1;
            }
            prev = x;
        }
        ans = max(ans,c);
        return ans;
        
    }
};