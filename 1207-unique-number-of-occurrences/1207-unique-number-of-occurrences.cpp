class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        map<int,int> mp;
        
        for(int i =0 ;i<arr.size();i++)
            mp[arr[i]]++;
        
        set<int> st;
        
        for(auto i:mp)
        {
            if(st.find(i.second)!=st.end())
                return 0;
            st.insert(i.second);
        }
        
        return 1;
    }
};