//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        vector<string> arr;
        
        string curr = "";
        
        for(int i=0;i<S.size();i++)
        {
            if(S[i]=='.')
            {
                if(curr.size())
                arr.push_back(curr);
                
                curr = "";
            }
            else
            curr += S[i];
        }
        if(curr.size())
                arr.push_back(curr);
                
        reverse(arr.begin(),arr.end());
        
        string ans ="";
        
        for(auto i:arr)
        {
            ans += i;
            ans+='.';
        }
        
        if(ans.size())
        ans.pop_back();
        
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
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends