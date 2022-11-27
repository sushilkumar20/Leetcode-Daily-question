//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        
        sort(arr,arr+N);
        
        string ans = arr[0];
        
        // bool ok =true;
        for(int i=1;i<N;i++)
        {
            string temp = "";
            
            for(int j=0;j<min(ans.size(),arr[i].size());j++)
            {
                if(ans[j]==arr[i][j])
                {
                    temp+=ans[j];
                }
                else
                break;
            }
            
            ans = temp;
        }
        
        if(ans.size()==0)
        return "-1";
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends