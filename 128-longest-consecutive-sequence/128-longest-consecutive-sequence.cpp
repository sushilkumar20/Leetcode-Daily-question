class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       
        set<int> st;
        
        for(int i=0;i<nums.size();i++)
            st.insert(nums[i]);
        
        
        int mx=0;
        for(auto i =st.begin();i!=st.end();i++)
        {
            if(st.find(*i-1)!=st.end())
            {
                continue;
            }
            else
            {
                int k = *i+1;
                int cnt=1;
                while(st.find(k)!=st.end())
                {
                    k++;
                    cnt++;
                }
                
                mx =max(mx,cnt);
            }
        }
        
        return mx;
    }
};