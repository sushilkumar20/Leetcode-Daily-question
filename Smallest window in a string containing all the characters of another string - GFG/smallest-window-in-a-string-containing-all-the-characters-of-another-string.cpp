//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int n = s.size();
        int mx = n+1;
        
        vector<int> arr(26,0);
        vector<int> tar(26,0);
        
        for(int i=0;i<p.size();i++)
        {
            tar[p[i]-'a']++;
        }
        
        int lw = -1;
        int ind =-1;
        for(int i=0;i<n;i++)
        {
            arr[s[i]-'a']++;
            
            bool ok=true;
            for(int j=0;j<26;j++)
            {
                if(arr[j]<tar[j])
                {
                    ok=0;
                    break;
                }
            }
            
            if(ok)
            {
                if(mx>abs(i-lw))
                {
                    ind=lw+1;
                    mx = abs(i-lw);
                }
                // mx=min(mx,abs(i-lw));
            }
            
            while(lw<i&&ok)
            {
                // cout<<lw<<" "<<i<<endl;
                arr[s[lw+1]-'a']--;
                bool ok=true;
                for(int j=0;j<26;j++)
                {
                    if(arr[j]<tar[j])
                    {
                        ok=0;
                        break;
                    }
                }
                
               
               
               if(mx>abs(i-lw))
                {
                    ind=lw+1;
                    mx = abs(i-lw);
                }
                
                 if(!ok){
                    // cout<<lw<<endl;
                    arr[s[lw+1]-'a']++;
                    break;
                }
                lw++;
            }
        }
        if(mx==n+1)
        {
            return "-1";
        }
        
        //  cout<<mx<<" "<<ind<<endl;
        return s.substr(ind,mx);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends