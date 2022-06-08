class Solution {
public:
    int removePalindromeSub(string s) {
        
        int mx = 2;
        
        int i = 0;
        int j = s.size()-1;
        
        bool ok = true;
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                ok=false;
                break;
            }
            
            i++;
            j--;
        }
        
        if(ok)
            return 1;
        
        return 2;
    }
};