//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    bool pos(int N, int start[],int  end[], int mid)
    {
        for(int i=mid;i<N;i++)
        {
            if(start[i]<end[i-mid])
            return 0;
        }
        
        return 1;
    }
    int minLaptops(int N, int start[], int end[]) {
        // Code here
        
        sort(start,start+N);
        sort(end,end+N);
        int lw = 1;
        int hg = N;
        
        int ans = hg;
        
        while(lw<=hg)
        {
            int mid = lw+(hg-lw)/2;
            if(pos(N,start,end,mid))
            {
                ans = min(ans,mid);
                hg=mid-1;
            }
            else
            {
                lw = mid+1;
            }
        }
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends