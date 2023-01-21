//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        
        vector<int> arr(32);
        
        int cnt = 0;
        int cnt1=0;
        for(int i=0;i<32;i++)
        {
            if((a&(1ll<<i))!=0)
            {
                arr[i]=1;
                cnt1++;
            }
            
            if((b&(1ll<<i))!=0)
            {
                cnt++;
            }
        }
        
        if(cnt1==cnt)
        return a;
        
        if(cnt1>cnt)
        {
            int x = 0;
            for(int i=31;i>=0&&cnt>0;i--)
            {
                if(arr[i])
                {
                    arr[i]=0;
                    cnt--;
                x+=(1<<i);
                }
            }
            
            
            
          
            
            return x;
        }
        else
        {
            cnt-=cnt1;
            
           
            
            int x = a;
            
            for(int i=0;i<32&&cnt>0;i++)
            {
                if(arr[i]==0){
                x+=(1<<i);
                cnt--;
                }
            }
            x=(x|a);
            
            return x;
        }
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends