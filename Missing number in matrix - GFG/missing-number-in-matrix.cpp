//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    long long int MissingNo(vector<vector<int> >& mat) {
        // Code here
        int n= mat.size();
        vector<vector<long long>> matrix(n,vector<long long>(n));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                matrix[i][j]=mat[i][j];
            }
        }
        int c = -1;
        int r = -1;
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j] == 0)
                {
                    r = i;
                    c = j;
                    break;
                }
            }
        }
        
        long long sum =0;
        for(int i=0;i<matrix.size();i++)
        {
           
            if(i!=r)
            {
                for(int j=0;j<matrix[0].size();j++)
                {
                    sum+=matrix[i][j];
                    // break;
                }
                break;
            }
        }
        
         long long x = sum;
       
        for(int i=0;i<matrix[0].size();i++)
        {
            sum -= matrix[r][i];
        }
         
        matrix[r][c] = sum;
        // cout<<matrix[r][c]<<endl;
        for(int i=0;i<matrix.size();i++)
        {
            long long y =0;
            for(int j=0;j<matrix[0].size();j++)
            {
                y+=matrix[i][j];
            }
            
            // cout<<y<<" "<<r<<endl;
            if(y!=x)
            return -1;
        }
        
         for(int i=0;i<matrix[0].size();i++)
        {
            long long y =0;
            for(int j=0;j<matrix.size();j++)
            {
                y+=matrix[j][i];
            }
            
            if(y!=x)
            return -1;
        }
        long long y =0;
        for(int i=0;i<matrix[0].size();i++)
        {
            
            y+=matrix[i][i];
    
            
        }
        
         if(y!=x)
            return -1;
            
            
        y=0;
        for(int i=0;i<matrix[0].size();i++)
        {
           
           
                y+=matrix[i][matrix.size()-i-1];
            
            
           
        }
        
         if(y!=x)
            return -1;
        if(sum<=0)
        return -1;
        return sum;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends