//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int H[], int N) {
        // code here
        
        vector<int> tmp;
        
        for(int i=0;i<N;i++)
        {
            if(i==0)
            {
                tmp.push_back(H[i]);
            }
            else
            {
                int x = lower_bound(tmp.begin(),tmp.end(),H[i])-tmp.begin();
                
                if(x>=tmp.size())
                tmp.push_back(H[i]);
                
                tmp[x] = H[i];
            }
        }
        
        return N-tmp.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends