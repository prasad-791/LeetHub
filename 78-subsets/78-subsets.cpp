class Solution {
public:
    vector<vector<int>> ans;
    void help(vector<int> nums, vector<int>& arr,int i){
        if(i>=nums.size()){
            ans.push_back(arr);
            return ;
        }
        // take or choose the element 
        arr.push_back(nums[i]);
        help(nums,arr,i+1);
        
        // don't take or not to choose the element
        arr.pop_back();
        help(nums,arr,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        help(nums,temp,0);
        return ans;
    }
};