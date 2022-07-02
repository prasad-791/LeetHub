const long long MOD = 1e9+7;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& ho, vector<int>& v) {
        sort(ho.begin(),ho.end());
        sort(v.begin(),v.end());
        
        int maxH = ho[0];
        for(int i=1;i<ho.size();i++){
            maxH = max(maxH,ho[i]-ho[i-1]);
        }
        maxH = max(maxH,h-ho[ho.size()-1]);
        
        int maxW = v[0];
        for(int i=1;i<v.size();i++){
            maxW = max(maxW,v[i]-v[i-1]);
        }
        maxW = max(maxW,w-v[v.size()-1]);
        
        return (int)((maxH%MOD)*(maxW%MOD)%MOD);
    }
};