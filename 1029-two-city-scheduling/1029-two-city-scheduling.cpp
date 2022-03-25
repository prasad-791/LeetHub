class Solution {

public: 


    int solve(vector<vector<int>> a, int n1, int n2,int i){
        if(n1==0 && n2==0){
            return 0;
        }
        
        if(n1>0 && n2>0){
            int x1 = a[i][0] + solve(a,n1-1,n2,i+1);
            int x2 = a[i][1] + solve(a,n1,n2-1,i+1);
            return min(x1,x2);
        }
        if(n1==0){
            return a[i][1] + solve(a,n1,n2-1,i+1);
        }
        return a[i][0] + solve(a,n1-1,n2,i+1);
    }
    
    int twoCitySchedCost(vector<vector<int>>& c) {
        int n = c.size();
        vector<vector<int>> a(n,vector<int>(3,0));
        for(int i=0;i<n;i++){
            a[i][0] = c[i][1]-c[i][0];
            a[i][1] = c[i][0];
            a[i][2] = c[i][1]; 
        }
        
        sort(a.begin(), a.end());
        int sum = 0,i=0;
        for(;i<n/2;i++){
            sum += a[i][2];
        }
        for(;i<n;i++){
            sum += a[i][1];
        }
        return sum;
    }
};