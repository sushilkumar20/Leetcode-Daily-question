class Solution {
public:
    
    int kmp(string target, string source)
    {
        int n = source.size();
        vector<int> lps(n,0);
        
        int i=1;
        int prev = 0;
        
        while(i<source.size())
        {
            if(source[i]==source[prev])
            {
                lps[i] = prev+1;
                prev++;
                    i++;
            }
            else {
               if(prev==0)
               {
                   lps[i]=0;
                   i++;
               }
                else
                {
                    prev=lps[prev-1];
                }
            }
        }
        
         i=0;
        int j=0;
        
        while(i<target.size())
        {
            if(target[i]==source[j])
            {
                i++;
                j++;
            }
            else
            {
                if(j==0)
                {
                   i++; 
                }
                else
                    j=lps[j-1];
            }
            
            if(j==source.size())
                return i-source.size();
        }
        
        return -1;
        
    }
    
    int strStr(string haystack, string needle) {
        
        if(needle.size()==0)
            return 0;
        
        return kmp(haystack, needle);
    }
};