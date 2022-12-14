//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findRange(string str, int n) {
        // code here
        int lft = -1;
        int rgt = -1;
        
        int curr = 0;
        int mx = 0;
        vector<int> arr;
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(str[i]== '1')
            {
                curr--;
                if(curr<0)
                {
                    cnt = i+1;
                    curr=0;
                }
                
                if(curr>mx)
                {
                    mx = curr;
                    lft = cnt;
                    rgt = i;
                }
            }
            else
            {
                
                curr++;
                if(curr>mx)
                {
                    mx = curr;
                    lft = cnt;
                    rgt = i;
                }
            }
            
            // cout<<lft<<endl;
            
        }
        
               
        if(lft==-1){
        arr.push_back(-1);
        return arr;
        }
        else
        return vector<int>{lft+1,rgt+1};
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends