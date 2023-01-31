//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) {
        // code here
        // cout<<A.size()<<" "<<B.size()<<endl;
        set<char> st;
        
        for(auto i:A)
        st.insert(i);
        
        
        for(auto i:B)
        {
            if(st.find(i)==st.end())
            return -1;
        }
        
        int fst = -1;
        
        for(int i=0;i<=B.size()-A.size();i++)
        {
            if(B.substr(i,A.size())==A)
            {
                fst = i;
                break;
            }
        }
        
       
        if(fst==-1)
        return -1;
        int cnt = 0;
        int lst = -1;
        for(int i=fst;i<B.size();i+=A.size())
        {
            if(B.substr(i,A.size())!=A)
            {
                lst = i;
                break;
            }
            cnt++;
        }
        fst--;
        if(fst!=-1)
        cnt++;
        int i = A.size()-1;
        while(fst>=0&&i>=0)
        {
            
            if(A[i]!=B[fst])
            return -1;
            fst--;
            i--;
        }
        
       
        i=0;
        while(lst!=-1&&lst<B.size()&&i<A.size())
        {
            // cout<<A[i]<<" "<<B
            if(A[i]!=B[lst])
            return -1;
            lst++;
            i++;
        }
        
        if(lst!=-1)
        cnt++;
        
        return cnt;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends