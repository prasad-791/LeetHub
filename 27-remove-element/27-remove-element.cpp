class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0){
            return 0;
        }
        int i=0,j = nums.size()-1;
        while(i<j){
            while(i<j && nums[j]==val){
                j--;
            }
            while(i<j && nums[i]!=val){
                i++;
            }
            if(nums[j]!=val && nums[i]==val){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        return nums[i]==val ? 0 : i+1;
    }
};