class Solution {
public:
    vector<int> dp;
    int help(vector<int> nums, int i, int prev){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=0;
        if(i==nums.size()-1){
            if(prev!=nums[i]){
                ans += 1;
            }
        }else if(prev==-1){
            ans += 1+help(nums,i+1,nums[i]);
        }else{
            int temp = INT_MIN;
            if( (nums[i]<prev && nums[i]<nums[i+1]) || (nums[i]>prev && nums[i]>nums[i+1]) ){
                temp = 1 + help(nums,i+1,nums[i]);
            }
            ans = max(temp,help(nums,i+1,prev));
        }
        return dp[i]=ans;
    }
    int wiggleMaxLength(vector<int>& nums) {
        dp = vector<int>(nums.size(),-1);
        int ans = 1+help(nums,1,nums[0]);
        ans = max(ans,help(nums,1,-1));
        return ans;
    }
};