class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n=nums.size();
        set<int> st;
        
        for(int i=0;i<n;i++)
        {
           st.insert(nums[i]); 
        }
        
        int mx=0;
        for(auto i = st.begin();i!=st.end();i++)
        {
            int x = *i;
            if(st.find(x-1)!=st.end())
            {
                continue;
                
            }
            else
            {
                int cnt=1;
                x++;
                while(st.find(x)!=st.end())
                {
                    cnt++;
                    x++;
                }
                
                mx=max(mx,cnt);
            }
        }
        
        return mx;
    }
};