class Solution {
public:
    bool halvesAreAlike(string s) {
        
        int length=s.size();
        
        int count1=0;
        int count2=0;
        
        for(int i=0;i<length/2;i++)
        {
            if(s[i]=='a'||s[i]=='A'||s[i]=='e'||s[i]=='E'||s[i]=='i'||s[i]=='I'||s[i]=='o'||s[i]=='O'||s[i]=='u'||s[i]=='U')
                count1++;
       
            }
        for(int i=length/2;i<length;i++)
        {
            if(s[i]=='a'||s[i]=='A'||s[i]=='e'||s[i]=='E'||s[i]=='i'||s[i]=='I'||s[i]=='o'||s[i]=='O'||s[i]=='u'||s[i]=='U')
                count2++;
       
            }
        
        if(count1==count2)
            return true;
        else
            return false;
        
    }
};