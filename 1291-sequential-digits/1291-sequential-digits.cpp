class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
          string s="123456789";
        vector<string> ss;
        for(int i=0;i<s.size();i++)
        {
            string a="";
            a+=s[i];
            for(int j=i+1;j<s.size();j++)
            {
                a+=s[j];
                ss.push_back(a);
            }
        }
        vector<int> ans;
        for(int i=0;i<ss.size();i++)
        {
            int k=stoi(ss[i]);
            if(k>=low&&k<=high)
                ans.push_back(k);
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};