//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    
	    int n= matrix.size();
	   // int m= matrix[0]
	    for(int i=0;i<n;i++)
	    {
	        for(int u=0;u<n;u++)
	        {
	            for(int v=0;v<n;v++)
	            {
	                if(matrix[u][i]==-1||matrix[i][v]==-1){
	                continue;
	                }
	                if(matrix[u][v]==-1)
	                {
	                    matrix[u][v] = matrix[u][i]+matrix[i][v];
	                    continue;
	                }
	                if(matrix[u][v]>matrix[u][i]+matrix[i][v])
	                {
	                    matrix[u][v] = matrix[u][i]+matrix[i][v];
	                }
	            }
	        }
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends