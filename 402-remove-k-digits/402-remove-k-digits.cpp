class Solution {
public:
    string removeKdigits(string num, int k) {
        
        
        int n=num.size();
        stack<char> st;
        int i;
        if(k>=num.size())
            return "0";
        for( i=0;i<num.size()&&k;i++)
        {
            if(st.size()==0)
                st.push(num[i]);
            else
            {
                while(st.size()!=0&&k&&st.top()>num[i])
                {
                    st.pop();
                    k--;
                }
                st.push(num[i]);
            }
        }
        
        string s="";
        
        while(st.size()!=0)
        {
            s+=st.top();
            st.pop();
        }
       
        reverse(s.begin(),s.end());
        
       
        
        for(i;i<num.size();i++)
            s+=num[i];
        
          int j;
        for( j=0;j<s.size();j++)
        {
            if(s[j]!='0')
                break;
        }
        
        s=s.substr(j);
        
        //cout<<k<<endl;
        if(k>=s.size())
            return "0";
        else
            s=s.substr(0,s.size()-k);
        
        if(s.size()==0)
            s="0";
        return s;
    }
};