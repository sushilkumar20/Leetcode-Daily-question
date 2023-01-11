//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        // Code here
        
        sort(arr.begin(),arr.end());
        
        set<int> st;
        int cnt=0;
        for(int i=0;i<N;i++)
        {
            if(st.size()==0){
            st.insert(arr[i]);
            continue;
            }
            
            if(st.find(arr[i])==st.end())
            {
                st.insert(arr[i]);
            }
            else
            {
                int k = *st.rbegin();
                
                k++;
                
                if(arr[i]>k)
                {
                    cnt++;
                    st.insert(arr[i]+1);
                }
                else
                {
                    cnt += k-arr[i];
                    st.insert(k);
                }
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
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends