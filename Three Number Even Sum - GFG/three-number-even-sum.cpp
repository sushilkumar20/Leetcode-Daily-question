// { Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int countWays(int n)
	{
		// Your code goes here
		
		int mod=1e9+7;
		long long k=n/2;
		
		if(n%2==0)
		{
		    long long ans=(k*(k-1)*(k-2)/6)+(k*(k-1)/2)*k;
		    
		    return ans%mod;
		}
		else
		{
		    long long ans=k*(k-1)*(k-2)/6+((k+1)*k/2)*k;
		     return ans%mod;
		}
	}
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

	    

	    Solution ob;
	    cout << ob.countWays(n) << "\n";
   
    }
    return 0;
}  // } Driver Code Ends