//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        // code here
        
        int n = words.size();
        
        sort(words.begin(),words.end());
        
        map<string,int> mp;
        mp[""]=1;
        for(int i=0;i<n;i++)
        {
            if(words.size()==1)
            {
                mp[words[i]]=1;
                continue;
            }
            if(mp.find(words[i].substr(0,words[i].size()-1))!=mp.end())
            {
                mp[words[i]]=1;
            }
        }
        
         string ans =  "";
         
         for(auto i:mp)
         {
             if(i.first.size()>ans.size())
             ans=i.first;
         }
         
         return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends