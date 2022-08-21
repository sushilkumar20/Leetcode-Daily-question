class Solution {
public:
    
    int find(string &target,string &stamp)
    {
        
        for(int i=0;i<=target.size()-stamp.size();i++)
        {
            int j=0;
            bool foundNon = false;
            while(j<stamp.size()&&(stamp[j]==target[i+j]||target[i+j]=='*'))
            {
                if(target[i+j]!='*')
                    foundNon = true;
                j++;
                
            }
            
            if(j==stamp.size()&&foundNon)
                return i;
        }
        
        return -1;
    }
    
    void update(int i, string &target, string &stamp)
    {
        for(int j=i;j<i+stamp.size();j++)
            target[j]='*';
    }
    vector<int> movesToStamp(string stamp, string target) {
        
        vector<int> ans;
        
        string tar="";
        
        for(int i=0;i<target.size();i++)
            tar+="*";
        
        while(tar!=target)
        {
          int ind = find(target,stamp);
           // cout<<ind<<" "<<target<<endl;
            if(ind<0)
            {
                return {};
            }
            else
            {
                update(ind,target,stamp);
            }
              ans.push_back(ind);
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};