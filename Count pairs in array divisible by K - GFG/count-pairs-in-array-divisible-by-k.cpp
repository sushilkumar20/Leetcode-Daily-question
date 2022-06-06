// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int arr[], int n, int K)
    {
        //code here
        
        for(int i=0;i<n;i++)
        {
            arr[i] = arr[i]%K;
        }
        
        map<int,long> freq;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            int rem = K-arr[i];
            
            if(rem == K)
            {
                ans += freq[0];
            }
            else
            {
                ans += freq[rem];
            }
            
            freq[arr[i]]++;
        }
        
        return ans;
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

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}
  // } Driver Code Ends