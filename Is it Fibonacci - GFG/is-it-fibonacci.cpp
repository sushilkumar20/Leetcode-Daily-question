//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        // code here
        
        vector<long long> arr(N+1);
        
        int j=1;
        long long sum = 0;
        for(int i=0;i<K;i++)
        {
            arr[i+1] = GeekNum[i];
            sum+=GeekNum[i];
        }
        
        for(int i=K;i<N;i++)
        {
            arr[i+1] = sum;
            
            sum = 2*arr[i+1]-arr[i+1-K];
        }
        
        return arr[N];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends