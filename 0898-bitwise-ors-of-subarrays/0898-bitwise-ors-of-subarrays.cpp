class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        
        unordered_set<int>st;
        unordered_set<int>ans;
        
        for(int i=0;i<arr.size();i++)
        {
            unordered_set<int> curr;
            
            for(auto j:st)
            {
                curr.insert((j|arr[i]));
            }
            curr.insert(arr[i]);
            
            st=curr;
            
            for(auto j:st)
                ans.insert(j);
        }
        
        return ans.size();
    }
};