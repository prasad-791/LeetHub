class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int num = 2;
        vector<vector<int>> a(n,vector<int>(n,0));
        a[0][0]=1;
        int i=0,j=0;
        int val = 0;
        while(!(i==n/2 && j==n/2)){
            if(val==0){
                j++;
                for(;j<n && a[i][j]==0;j++){
                    a[i][j]=num++;
                }
                j--;
            }else if(val==1){
                i++;
                for(;i<n && a[i][j]==0;i++){
                    a[i][j]=num++;
                }
                i--;
            }else if(val==2){
                j--;
                for(;j>=0 && a[i][j]==0;j--){
                    a[i][j]=num++;
                }
                j++;
            }else{
                i--;
                for(;i>=0 && a[i][j]==0;i--){
                    a[i][j]=num++;
                }
                i++;
            }
            val = (val+1)%4;
        }
        if(n%2==0){
            j--;
            a[i][j] = num;
        }
        return a;
    }
};