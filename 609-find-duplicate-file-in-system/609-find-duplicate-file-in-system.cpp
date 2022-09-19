class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
          map<string,vector<string>> mp;
        
        for(int i=0;i<paths.size();i++)
        {
            bool ok=true;
            string dir="";
            string val="";
            string last="";
            bool kk=true;
            for(int j=0;j<paths[i].size();j++)
            {
                if(ok&&paths[i][j]!=' ')
                {
                    dir+=paths[i][j];
                }
                else if(ok &&paths[i][j]==' ')
                {
                    ok=false;
                    kk=true;
                }
                else if(!ok&&paths[i][j]!=' ')
                {
                    if(kk&&paths[i][j]!='(')
                        last+=paths[i][j];
                    else if(paths[i][j]=='(')
                    {
                        kk=false;
                        continue;
                    }
                    if(!kk&&paths[i][j]!=')')
                    {
                        val+=paths[i][j];
                    }
                    else if(paths[i][j]==')')
                    {
                        if(last.size()!=0)
                        mp[val].push_back(dir+'/'+last);
                        last="";
                        val="";
                        kk=true;
                        continue;
                        
                    }
                }
            }
            
            
        }
        
        vector<vector<string>> arr;
        
        for(auto i:mp)
        {
            //cout<<i.first<<endl;
            if(i.second.size()>=2){
               
                arr.push_back(i.second);
            }
        }
        
        return arr;
    }
};