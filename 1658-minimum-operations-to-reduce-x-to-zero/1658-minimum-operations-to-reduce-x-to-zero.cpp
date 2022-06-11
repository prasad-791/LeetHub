class Solution {
public:
    int lenOfLongSubarr(vector<int> A, int N, int K){
    int i = 0, j = 0, sum = 0;
    int maxLen = INT_MIN;
   
    while (j < N) {
        sum += A[j];
        if (sum < K) {
            j++;
        }
        else if (sum == K) {
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        else if (sum > K) {
            while (sum > K) {
                sum -= A[i];
                 i++;
            }
              if(sum == K){
              maxLen = max(maxLen, j-i+1);
            }
            j++;
        }
    }
    return maxLen;
}
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int req = sum-x;
        if(req<0){
            return -1;
        }
        int len = lenOfLongSubarr(nums,nums.size(),req);
        return len == INT_MIN ? -1 :nums.size()-len;
    }
};