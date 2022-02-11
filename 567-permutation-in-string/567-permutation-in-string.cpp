class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int> arr(26,0);
        int n=s1.size();
        for(int i=0;i<s1.size();i++)
            arr[(int)(s1[i]-'a')]++;
        
        
         vector<int> brr(26);
        for(int i=0;i<s2.size();i++)
        {
           brr[s2[i]-'a']++;
            
            if(i>=n)
            {
                brr[s2[i-n]-'a']--;
            }
            
            bool ok=true;
            for(int j=0;j<26;j++)
            {
                if(arr[j]!=brr[j])
                {
                    ok=false;
                    break;
                }
                
            
            }
            
            if(ok)
                return true;
           
        }
        
            
        return false;
    }
};