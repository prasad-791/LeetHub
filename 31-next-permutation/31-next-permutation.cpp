class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return ;
        int i;
        for(i=n-1;i>=1 && nums[i]<=nums[i-1];i--);
        
        if(i==n-1){
            int temp = nums[n-1];
            nums[n-1] = nums[n-2];
            nums[n-2] = temp;
            return ;
        }
        
        if(i==0){
            sort(nums.begin(),nums.end());
            return ;
        }
        
        int j = i-1;
        int k = nums[j+1],index = j+1;
        for(int x=j+2;x<nums.size();x++){
            if(nums[x]>nums[j] && nums[x]<k){
                k = nums[x];
                index = x;
            }
        }
        int temp = nums[j];
        nums[j] = nums[index];
        nums[index] = temp;
        sort(nums.begin()+i,nums.end());
        return ;
    }
};