//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        // Your code goes here
        
        sort(A,A+n);
        sort(B,B+m);
        
        long long sum1 = 0;
        
        for(int i=0;i<n;i++)
        {
            sum1+=A[i];
        }
        
        long long sum2 = 0;
        
        for(int i=0;i<m;i++)
        {
            sum2+=B[i];
        }
        
        
        int totalSm = sum1+sum2;
        if(totalSm%2)
        return -1;
        
        
        int rq = totalSm/2;
        
        int diff = sum1 - rq;
        
        for(int i=0;i<n;i++)
        {
            int z = A[i] - diff;
            
            int lw = 0;
            int hg = m-1;
            
            while(lw<=hg)
            {
                int mid = (lw+hg)/2;
                
                if(B[mid]==z)
                return 1;
                
                if(B[mid]>z)
                {
                    hg=mid-1;
                }
                else
                {
                    lw=mid+1;
                }
            }
        }
        
        return -1;
        
	}
 

};

//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}






// } Driver Code Ends