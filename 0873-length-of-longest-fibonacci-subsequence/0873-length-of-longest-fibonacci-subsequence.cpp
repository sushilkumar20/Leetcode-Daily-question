class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        
        unordered_set<int> st;
        
        for(int i=0;i<arr.size();i++)
            st.insert(arr[i]);
        
        int mx = 0;
        
        for(int i=0;i<arr.size();i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                int len = 2;
                
                int x = arr[i];
                int y = arr[j];
                
                while(st.find(x+y)!=st.end())
                {
                    len++;
                    mx=max(mx,len);
                    
                    int z = x+y;
                    x=y;
                    y=z;
                }
            }
        }
        
        return mx;
    }
};