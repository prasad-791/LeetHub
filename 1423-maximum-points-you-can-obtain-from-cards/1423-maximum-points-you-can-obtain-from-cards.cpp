class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int ans = INT_MIN;
        int sum =0;
        int i=0;
        while(i<k){
            sum += c[i++];
        }
        i--;
        ans = sum;
        int j=c.size()-1;
        while(i>=0){
            sum -= c[i];
            sum += c[j];
            ans = max(ans,sum);
            i--;
            j--;
        }
        return ans;
    }
};