//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    //Complete the function and return minimum number of operations
    public:
    int specialPalindrome(string s1, string s2){
        //Code Here
        int ans = INT_MAX;
        for(int i=0;i<=s1.size()-s2.size();i++)
        {
            bool ok = 1;
            
            int x = 0;
            int y = i;
            int cnt = 0;
            
            for(x;x<s2.size();x++)
            {
                if(s2[x]!=s1[y])
                cnt++;
                
                
                swap(s2[x],s1[y]);
                
                y++;
            }
            
            x=0;
            y=s1.size()-1;
            
            while(x<y)
            {
               if(s1[x]!=s1[y])
               {
                   if(x<i||x>=i+s2.size())
                  cnt++;
                  else if(y<i||y>=i+s2.size())
                  cnt++;
                  else
                  {
                      ok=0;
                      break;
                  }
               }
               x++;
               y--;
            }
            
            
            
                //  cout<<cnt<<endl;
                 if(ok)
                ans=min(ans,cnt);
            
            
            x = 0;
            y = i;
           
            
            for(x;x<s2.size();x++)
            {
                swap(s2[x],s1[y]);
                y++;
            }
            
        }
        
        if(ans == INT_MAX)
        return -1;
        
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        Solution obj;
        int ans = obj.specialPalindrome(s1,s2);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends