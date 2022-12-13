//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    // your code here
    map<int,int> mp;
    
    int mx = 0;
    int lw = -1;
    for(int i=0;i<S.size();i++)
    {
        if(mp[S[i]]==0)
        {
            mx = max(mx,i-lw);
            mp[S[i]]++;
        }else
        {
            int j = lw+1;
            mp[S[i]]++;
            while(mp[S[i]]>1&&j<i)
            {
                lw =j;
                
                mp[S[j]]--;
                j++;
            }
        }
    }
    
    return mx;
}