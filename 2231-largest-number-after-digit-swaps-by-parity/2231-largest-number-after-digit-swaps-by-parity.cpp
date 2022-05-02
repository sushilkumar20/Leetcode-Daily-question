class Solution {
public:
    int largestInteger(int num) {
        
        string s = to_string(num);
        
        string odd="";
        string even="";
        
        for(int i=0;i<s.size();i++)
        {
            if((int)(s[i]-'0')%2==0)
                even+=s[i];
            else
                odd+=s[i];
        }
        
        sort(odd.rbegin(),odd.rend());
        sort(even.rbegin(),even.rend());
        
        int i=0;
        int j=0;
       //cout<<even[0]<<endl;
        string ans="";
        for(int k=0;k<s.size();k++)
        {
            if((int)(s[k]-'0')%2==0)
            {
                
                ans+=even[i];
                i++;
            }
            else
            {
                ans+=odd[j];
                j++;
            }
        }
        
        return stoi(ans);
        
    }
};