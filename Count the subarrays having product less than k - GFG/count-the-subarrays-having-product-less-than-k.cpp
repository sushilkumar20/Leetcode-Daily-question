// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        
        int start=0;
        int end=0;
        
        long long p=1;
        long long cnt=0;
        for(;start<n&&end<n;end++)
        {
            p*=(long long)a[end];
            
            while(start<n&&p>=k)
            {
                p=p/a[start];
                start++;
            }
            
            if(p<k)
            cnt+=(long long)(end-start+1);
        }
        
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends