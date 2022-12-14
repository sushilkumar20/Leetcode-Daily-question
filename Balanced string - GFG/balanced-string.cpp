//{ Driver Code Starts
// Initial template for c++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++

class Solution {
  public:
    string BalancedString(int n) {
        // code here
        
        string s ="abcdefghijklmnopqrstuvwxyz";
        string s1 = s;
        reverse(s1.begin(),s1.end());
        
        string ans = "";
        
        int tp=n;
        while(n>26)
        {
            ans+=s;
            n-=26;
        }
        
        
        if(n%2==0)
        {
            int x = n/2;
            
            ans+=s.substr(0,x);
            ans+=s.substr(26-x);
        }
        else
        {
            int x = (n+1)/2;
            int y = (n-1)/2;
            int z = tp;
            
            int cnt=0;
            
            while(z>0)
            {
                cnt+=z%10;
                z=z/10;
            }
            
            if(cnt%2==0)
            {
                ans+=s.substr(0,x);
                ans+=s.substr(26-y);
            }
            else
            {
                 ans+=s.substr(0,y);
                // cout<<s.substr(0,y)<<endl;
                 ans+=s.substr(26-x);
                 
                //  cout<<
                 
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
        Solution ob;
        cout << ob.BalancedString(N) << endl;
    }
    return 0;
}

// } Driver Code Ends