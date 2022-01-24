class Solution {
public:
    bool detectCapitalUse(string words) {
        
        int c=0;
        
        for(int i=0;i<words.size();i++)
        {
            if(words[i]>='A'&&words[i]<='Z')
                c++;
        }
        
        if(c==0||c==words.size())
            return true;
        
        if(c==1&&words[0]>='A'&&words[0]<='Z')
            return true;
        
        return false;
    }
};