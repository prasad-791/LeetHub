class Solution {
public:
    int m,n;
    void dfs(vector<vector<int>>& image, int i, int j, int color, int newColor){
        if(i==-1 || i==m || j==-1 || j==n || image[i][j]!=color){
            return ;
        }
        image[i][j] = newColor;
        dfs(image,i+1,j,color,newColor);
        dfs(image,i-1,j,color,newColor);
        dfs(image,i,j+1,color,newColor);
        dfs(image,i,j-1,color,newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        if(image[sr][sc]!=color){
            dfs(image,sr,sc,image[sr][sc],color);
        }
        return image;
    }
};