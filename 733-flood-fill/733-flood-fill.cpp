class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& image, int fColor, int sColor)
    {
        if(i>=image.size()||j>=image[0].size()||i<0||j<0||image[i][j] !=sColor)
            return ;
        if(image[i][j] == fColor)
            return;
        image[i][j] = fColor;
        
        dfs(i+1,j,image,fColor,sColor);
        dfs(i,j+1,image,fColor,sColor);
        dfs(i-1,j,image,fColor,sColor);
        dfs(i,j-1,image,fColor,sColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)    {
        
        dfs(sr,sc,image,color,image[sr][sc]);
        
        return image;
    }
};