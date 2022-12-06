//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long jumpingNums(long long X) {
        // code here
        
        queue<long long> q;
        long long ans = 1;
        
        for(long long i=1;i<=9;i++){
            if(i<=X)
            {
                ans=max(ans,i);
                q.push(i);
            }
        }
        
        
        
        while(q.size())
        {
            long long x = q.front();
            
            q.pop();
            
            int rm = x%10;
            if(rm == 9)
            {
                x = (x*10+(rm-1));
                
                 if(x<=X){
                    q.push(x);
                    ans=max(ans,x);
                }
            }
            else if(rm == 0)
            {
                x = (x*10+(rm+1));
            
                
                if(x<=X){
                q.push(x);
                ans=max(ans,x);
                }
            }
            else
            {
                long long n = x*10+(rm-1);
                
                if(n<=X){
                q.push(n);
                ans=max(ans,n);
                }
                
                 n = x*10+(rm+1);
                
                if(n<=X){
                q.push(n);
                ans=max(ans,n);
                }
                
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
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends