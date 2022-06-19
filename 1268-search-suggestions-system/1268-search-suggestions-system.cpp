class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
          sort(products.begin(),products.end());
        
        
        int n=searchWord.size();
        string s="";
        vector<vector<string>> ans;
        for(int i=0;i<n;i++)
        {
            s+=searchWord[i];
            vector<string> tt;
            for(int j=0;j<products.size();j++)
            {
               if(s==products[j].substr(0,s.size()))
               {
                   tt.push_back(products[j]);
               }
                if(tt.size()==3)
                    break;
            }
            ans.push_back(tt);
        }
        
        return ans;
    }
};