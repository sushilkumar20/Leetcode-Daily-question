//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string S)
    {
        // code here
        
        int cnt = 0;
        
        for(int i=0;i<S.size();i++)
        {
            int x = 0;
            int y = 0;
            
            for(int j=i;j<S.size();j++)
            {
                if(S[j]>='A'&&S[j]<='Z')
                x++;
                
                if(S[j]>='a'&&S[j]<='z')
                y++;
                
                if(x == y)
                cnt++;
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends