//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        // Complete the function
        
        sort(a,a+n);
        
        map<int,int> mp;
        
        for(int i=0;i<n;i++)
        mp[a[i]]++;
        
        int ans = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(mp[a[i]]>0)
            {
                ans+=a[i];
                  mp[a[i]-1]--;
            }
            mp[a[i]]--;
          
        }
        
        return ans;
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends