class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        
        if(m==1) return high;
        
        if(m==nums.size()) return low;
        
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            
            int sum = 0, count = 1;
            for(int i=0;i<nums.size();i++){
                if(sum+nums[i]<=mid){
                    sum += nums[i];
                }else{
                    count++;
                    sum = nums[i];
                }
            }
            if(count>m){
                low = mid+1;
            }else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};