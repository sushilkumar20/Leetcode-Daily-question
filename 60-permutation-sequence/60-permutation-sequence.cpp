class Solution {
public:
    void help(int i, int n, int k,vector<string>&ans,string s,set<int>&st)
    {
        if(s.size()==n)
        {
            ans.push_back(s);
            return;
        }
        if(i>n)
            return;
        
        for(int j = 1;j<=n;j++)
        {
           if(st.find(j) != st.end())
               continue;
           
            s+=to_string(j);
            st.insert(j);
            help(i+1,n,k,ans,s,st);
            s.pop_back();
            auto k=st.find(j);
            st.erase(k);
            
        }
    }
    string getPermutation(int n, int k) {
        
      string ans ="";
        
        vector<int> arr;
        
        int fact =1;
        
        for(int i=1;i<n;i++)
        {
            fact = fact*i;
            arr.push_back(i);
        }
        
        arr.push_back(n);
        k--;
        while(true)
        {
            ans += to_string(arr[k/fact]);
            arr.erase(arr.begin()+k/fact);
            
            if(arr.size()==0)
                break;
            
                   k = k % fact;
                  fact = fact / arr.size();
        }
        
        return ans;
    }
};