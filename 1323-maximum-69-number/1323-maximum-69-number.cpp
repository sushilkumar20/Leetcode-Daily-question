class Solution {
public:
    int maximum69Number (int num) {
        
        
        string s = to_string(num);
        
        int i = 0;
        int j = s.size();
        
        while(i<j)
        {
           if(s[i]=='6')
           {
               s[i]='9';
               break;
           }
            i++;
        }
        
        return stoi(s);
    }
};