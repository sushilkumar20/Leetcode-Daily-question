//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        static bool cmp(int a, int b)
        {
            if(a>b)
            return 1;
            
            return 0;
        }
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            // Code here
            
            int prv = 0;
            
            for(int i=1;i<n;i++)
            {
                if((a[i]+a[i-1])%2)
                {
                    sort(a.begin()+prv,a.begin()+i,cmp);
                    prv=i;
                }
            }
            
            sort(a.begin()+prv,a.end(),cmp);
            
            return a;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends