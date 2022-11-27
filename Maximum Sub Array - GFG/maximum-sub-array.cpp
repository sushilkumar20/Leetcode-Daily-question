//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    
	    
	    
	    int sum = 0;
	    int mx =0;
	    
	    int l =-1;
	    int r = -1;
	    
	    int al=l;
	    int ar = r;
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]>=0)
	        {
	            sum+=a[i];
	            if(l==-1)
	            {
	                l=i;
	            }
	            
	            r=i;
	        }
	        else
	        {
	            if(sum>mx)
	            {
	                mx=sum;
	                ar=r;
	                al=l;
	            }
	            else if(sum==mx)
	            {
	                if(ar-al>r-l)
	                {
	                    ar=r;
	                    al=l;
	                    
	                }
	            }
	            
	            l = -1;
	            r = -1;
	            sum=0;
	            
	        }
	    }
	    
	    
	            if(sum>mx)
	            {
	                mx=sum;
	                ar=r;
	                al=l;
	            }
	            else if(sum==mx)
	            {
	                if(ar-al>r-l)
	                {
	                    ar=r;
	                    al=l;
	                    
	                }
	            }
	            
	            l = -1;
	            r = -1;
	            sum=0;
	            
	            
	    vector<int> ans;
	   //cout<<al<<" "<<ar<<endl;
	   if(ar>=0){
	    for(int i=al;i<=ar;i++)
	    ans.push_back(a[i]);
	   }
	    
	    if(ans.size()==0)
	    ans.push_back(-1);
	    
	    return ans;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends