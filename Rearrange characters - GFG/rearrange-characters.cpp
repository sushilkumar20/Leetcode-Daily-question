//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
    public:
    string rearrangeString(string str)
    {
        //code here
        int n=str.size();
        string ans = str;
        
        vector<int> freq(26,0);
        
        for(int i=0;i<str.size();i++)
        {
            freq[str[i]-'a']++;
        }
        
        priority_queue<pair<int,char>> pq;
        
       for(int i=0;i<26;i++)
        {
            if(freq[i]>0)
            pq.push({freq[i],'a'+i});
        }
        
        int i=0;
        while(pq.size())
        {
            int x = pq.top().first;
            char y = pq.top().second;
            pq.pop();
            while(x>0)
            {
                if(i>=n)
                i=1;
                
                ans[i] = y;
                x--;
                i+=2;
            }
        }
        
        // cout<<ans<<endl;
        
        for(int i=0;i<n-1;i++)
        if(ans[i]==ans[i+1])
        return "-1";
        
        return ans;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends