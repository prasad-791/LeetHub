class Solution {
public:
    
    int solve(vector<int> t, vector<int> b, vector<int> tf, vector<int> bf,int i, int n){
        if(i>=n){
            return 0;
        }
        int ds = solve(t,b,tf,bf,i+1,n);
        tf[b[i]]++;
        tf[t[i]]--;
        bf[b[i]]--;
        bf[t[i]]++;
        if(bf[t[i]]==n || tf[b[i]]==n){
            return 1;
        }
        int temp = b[i];
        b[i] = t[i];
        t[i] = temp;
        int s = solve(t,b,tf,bf,i+1,n);
        return min(ds,s); 
    }
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        vector<int> tf(7,0);
        vector<int> bf(7,0);
        int n = t.size();
        vector<int> same(7,0);
        
        for(int i=0;i<n;i++){
            tf[t[i]]++;
            bf[b[i]]++;
            if(t[i]==b[i]){
                same[t[i]]++;
            }
        }
        for(int i=1;i<7;i++){
            if(tf[i]+bf[i]-same[i]==n){
                return n-max(tf[i],bf[i]);       
            }
        }
        return -1;
    }
};

/*

int ans = INT_MAX, n=tops.size();
        for(int i=0;i<n;i++){
            int req = n-tf[tops[i]];
            if(bf[tops[i]]>=req){
                ans = min(req,ans);
            }
        }
        for(int i=0;i<n;i++){
            int req = n-bf[bottoms[i]];
            if(tf[bottoms[i]]>=req){
                ans = min(req,ans);
            }
        }
        return ans;
        
*/