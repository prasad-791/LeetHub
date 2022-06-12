class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0,j=0;
        map<int,int> mp;
        int ans = INT_MIN, sum=0;
        while(j<nums.size()){
            if(mp.count(nums[j])==0 || mp[nums[j]]==0){
                mp[nums[j]] = 1;
                sum += nums[j];
                j++;
            }else if(mp[nums[j]]==1){
                while(i <nums.size() && mp[nums[j]]==1){
                    mp[nums[i]]--;
                    sum -= nums[i]; 
                    i++;
                }
                sum += nums[j];
                mp[nums[j]] = 1;
                j++;
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};