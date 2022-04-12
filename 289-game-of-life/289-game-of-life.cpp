class Solution {
public:
    void help(vector<vector<int>>& b, int x,int y){
        int n = b.size();
        int m = b[0].size();
        
        for(int i=x-1;i<=x+1;i++){
            if(i>=0 && i<n){
                for(int j=y-1;j<=y+1;j++){
                    if(j>=0 && j<m && !(i==x && j==y)){
                        if(b[i][j]==1){
                            b[i][j] *= 10;
                        }
                        b[i][j]+=3;
                    }
                }
            }
        }
    }
    void gameOfLife(vector<vector<int>>& b) {
        int n = b.size();
        int m = b[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(b[i][j]%3!=0){
                    help(b,i,j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int num = b[i][j];
                b[i][j] = (num==16 || num==19 || num==9);
            }
        }
    }
};