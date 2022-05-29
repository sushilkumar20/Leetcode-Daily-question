class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int n = words.size();
        
        vector<int> freq(n);
        
        for(int i=0;i<words.size();i++)
        {
            int p=0;
            for(int j=0;j<words[i].size();j++)
            {
                int k = words[i][j]-'a';
                p = (p|(1<<k));
            }
            freq[i] = p;
        }
        
        int mx =0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if((freq[i]&freq[j])==0)
                    mx=max(mx,(int)(words[i].size()*words[j].size()));
            }
        }
        
        return mx;
    }
};