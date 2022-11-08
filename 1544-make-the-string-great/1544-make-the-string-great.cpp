class Solution {
public:
    string makeGood(string s) {
        
        int n=s.length();
        
        for(int i=0;i<s.length();i++)
        {
            if(abs(s[i]-s[i+1])==32)
            {
                s.erase(i, 2);
                i=-1;
            }
        }
        
        return s;
    }
};