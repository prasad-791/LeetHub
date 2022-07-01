class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        if(a[1]==b[1]){
            return a[0]<b[0];
        }
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int ans=0; 
        for(int i=0;i<boxTypes.size() && truckSize>0;i++){
            vector<int> b = boxTypes[i];
            if(truckSize>=b[0]){
                ans += b[0]*b[1];
            }else{
                ans += truckSize*b[1];
            }
            truckSize -= b[0];
        }
        return ans;
    }
};