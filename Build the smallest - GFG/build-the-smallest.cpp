//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    //code here.
    int n = num.size();
    stack<char> st;
    
    for(int i=0;i<n;i++)
    {
        while(st.size()&&k>0&&num[i]<st.top())
        {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    
    while(k>0&&st.size())
    {
        st.pop();
        k--;
    }
    
    string ans = "";
    while(st.size())
    {
        ans+=st.top();
        st.pop();
    }
    
    // cout<<ans.size()<<endl;
    reverse(ans.begin(),ans.end());
    int i=0;
    
    while(i<ans.size()-1&&ans[i]=='0')
    i++;
    
    return ans.substr(i);
}