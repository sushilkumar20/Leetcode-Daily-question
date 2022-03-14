class Solution {
public:
    string simplifyPath(string path) {
        
        int n=path.size();
        vector<string> st;
        
        
        int i=0;
        
        while(i<path.size())
        {
            string p="";
            
            if(path[i]=='/'){
                i++;
                continue;
            }
            else
            {
                while(i<n&&path[i]!='/')
                {
                    p+=path[i];
                    i++;
                }
                
                if(p==".")
                    continue;
                else
                {
                    if(p=="..")
                    {
                        if(st.size()>=1)
                            st.pop_back();
                    }
                    else
                        st.push_back(p);
                }
                    
            }
        }
    
       
        string s="";
        
        if(st.size()==0)
            return "/";
        
       for(int i=0;i<st.size();i++){
            s=s+"/";
            s+=st[i];
        }
        
        return s;
            
    }
};