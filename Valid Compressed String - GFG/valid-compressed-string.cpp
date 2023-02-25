//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        // code here
        int n = S.size();
        int m = T.size();
        
        
        int i =0;
        int j =0;
        
        while(i<n&&j<m)
        {
            string x = "";
            if(T[j]>='A'&&T[j]<='Z')
            {
                if(S[i]!=T[j])
                return 0;
                
                i++;
                j++;
            }
            else
            {
                while(j<T.size()&&T[j]>='0'&&T[j]<='9')
                {
                    x+=T[j];
                    j++;
                }
                
                int y = stoi(x);
                
                i+=y;
            }
        }
        
        if(i==S.size()&&j==T.size())
        return 1;
        
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends