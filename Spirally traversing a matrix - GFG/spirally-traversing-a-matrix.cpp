//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        
        int n = matrix.size();
        int m = matrix[0].size();
        
         r = 0;
         c = 0;
        int cnt =0;
        
        vector<int> ans;
        while(n>r&&m>c)
        {
            if(cnt%4==0)
            {
                for(int i=c;i<m;i++)
                {
                    ans.push_back(matrix[r][i]);
                }
                r++;
            }
            else if(cnt%4==1)
            {
                for(int i=r;i<n;i++)
                {
                    ans.push_back(matrix[i][m-1]);
                }
                
                m--;
                
            }
            else if(cnt%4==2)
            {
                for(int i=m-1;i>=c;i--)
                {
                    ans.push_back(matrix[n-1][i]);
                }
                
                n--;
            }
            else if(cnt%4==3)
            {
                for(int i=n-1;i>=r;i--)
                {
                    ans.push_back(matrix[i][c]);
                }
                
                c++;
            }
            
            cnt++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends