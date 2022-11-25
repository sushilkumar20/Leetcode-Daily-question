class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        int mod = 1e9+7;
        
        long long ans = 0;
        
        vector<int> left(n,n);
        stack<int> st;
        
        for(int i=0;i<arr.size();i++)
        {
            while(st.size()&&arr[st.top()]>arr[i])
            {
                left[st.top()]=i;
                st.pop();
            }
            
            st.push(i);
        }
        
        while(st.size())
            st.pop();
        vector<int> right(n,-1);
        
         for(int i=arr.size()-1;i>=0;i--)
        {
            while(st.size()&&arr[st.top()]>=arr[i])
            {
                right[st.top()]=i;
                st.pop();
            }
            
            st.push(i);
        }
        
       for(int i=0;i<n;i++)
       {
           long long l = left[i]-i;
           long long r = i-right[i] ;
           // cout<<arr[i]<<" "<<l<<" "<<r<<endl;
           ans = (ans+arr[i]*l*r)%mod;
       }
        
        return ans;
    }
};