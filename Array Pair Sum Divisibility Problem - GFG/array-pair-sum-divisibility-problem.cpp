//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        
        if(nums.size()%2)
        return 0;
        map<int,int> mp;
        
        for(int i=0;i<nums.size();i++)
        mp[nums[i]%k]++;
        
        // int cnt = 0;
        
        for(auto i:mp)
        {
            int x = i.second;
            int rem = k-i.first;
            
            if(k==rem)
            {
                if(x%2)
                return 0;
            }
            else
            {
                if(x!=mp[rem])
                return 0;
            }
        }
        
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends