//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:


   void dfs(int i, int j, int nw, vector<vector<int>>&image, int old )
   {
       if(i<0||j<0||i>=image.size()||j>=image[0].size())
       return;
       
       if(image[i][j]!=old)
       return;
       
       image[i][j]=nw;
       
       dfs(i+1,j,nw,image,old);
       dfs(i-1,j,nw,image,old);
       dfs(i,j+1,nw,image,old);
       dfs(i,j-1,nw,image,old);
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        
        int n = image.size();
        int m = image[0].size();
        
        
         vector<vector<int>> vis(n, vector<int>(m,0));
         if(image[sr][sc]==newColor)
         return image;
         
        
        dfs(sr,sc,newColor,image,image[sr][sc]);
        
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends