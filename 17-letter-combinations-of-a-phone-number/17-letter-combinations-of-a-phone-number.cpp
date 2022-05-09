class Solution {
public:
    void help(int i, string&digits,vector<string>&arr,vector<string>&ans,string &s)
    {
        if(i>=digits.size()){
           if(s.size())
            ans.push_back(s);
            return;
        }
        
       
        int k=(int)(digits[i]-'0');
         k-=2;
        for(int j=0;j<arr[k].size();j++)
        {
           
            s+=arr[k][j];
            help(i+1,digits,arr,ans,s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        
        vector<string> arr ={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        vector<string>  ans;
         string s="";
        int i=0;
        
        help(i,digits,arr,ans,s);
        
        return ans;
    }
};