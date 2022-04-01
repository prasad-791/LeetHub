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
        // vector<int> temp;
        // help(nums,temp,0);
        // return ans;
        
        int n = nums.size();
        int total = (1<<n) - 1;
        
        for(int i=0;i<=total;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                if(i & 1<<j){
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};