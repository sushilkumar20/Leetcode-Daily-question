class Solution {
public:
    bool is(string s)
    {
         int i=0;
        int j=s.size()-1;
       
        while(j>i)
        {
            if(s[i]!=s[j])
            {
               return false;
            }
            i++;
            j--;
        }
        
        
            return true;
    }
    bool validPalindrome(string s) {
        
        int i=0;
        int j=s.size()-1;
        
        int x=-1;
        int y=-1;
        
        while(j>i)
        {
            if(s[i]!=s[j])
            {
                x=i;
                y=j;
                break;
            }
            i++;
            j--;
        }
        
        if(x==-1)
            return true;
        
        string s1=s.substr(0,x);
        s1+=s.substr(x+1);
        //cout<<s1<<endl;
        if(is(s1))
        return true;
        
       
        s1=s.substr(0,y);
        s1+=s.substr(y+1);
        
         if(is(s1))
        return true;
        
        return false;
    }
};