//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &arr) {
        // code here
        
        stack<int> st;
        
        for(int i=0;i<N;i++)
        {
            while(st.size()&&arr[st.top()]<abs(arr[i])&&arr[i]<0&&arr[st.top()]>0)
            {
                st.pop();
            }
            
            if(st.size())
            {
                if(arr[i]<0)
                {
                    if(arr[st.top()]==abs(arr[i]))
                    st.pop();
                    else if(arr[st.top()]<0)
                    st.push(i);
                }
                else
                st.push(i);
            }
            else
           {
               st.push(i);
           }
        //   cout<<st.size()<<endl;
        }
        
        vector<int> ans;
        
        while(st.size())
        {
            ans.push_back(arr[st.top()]);
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
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

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends