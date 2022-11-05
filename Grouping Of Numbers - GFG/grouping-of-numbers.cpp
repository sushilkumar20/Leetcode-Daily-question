//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int arr[], int N, int K) {
        // code here
        
        map<int,int> mp;
        
        for(int i=0;i<N;i++)
        {
            mp[arr[i]%K]++;
        }
        
        int cnt=0;
        for(auto i:mp)
        {
            if(i.first==0||i.first==K-i.first)
            {
                cnt++;
            }
            else
            {
                cnt+=max(mp[i.first],mp[K-i.first]);
                mp[i.first]=0;
                mp[K-i.first]=0;
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends