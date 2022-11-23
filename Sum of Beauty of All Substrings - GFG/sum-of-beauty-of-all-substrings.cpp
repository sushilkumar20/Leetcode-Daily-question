//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        
        int ans = 0;
        for(int i=0;i<s.size();i++)
        {
            vector<int> freq(26,0);
            for(int j=i;j<s.size();j++)
            {
                freq[s[j]-'a']++;
                
                int mn =0;
                int mx =0;
                
                for(int k=0;k<26;k++)
                {
                    if(freq[k]>mx)
                    {
                        mx=freq[k];
                        
                    }
                    
                    if(mn==0)
                    mn=freq[k];
                    
                    if(freq[k]>0)
                    mn=min(mn,freq[k]);
                }
                
                // cout<<mx<<" "<<mn<<endl;
                ans+=(mx-mn);
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
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends