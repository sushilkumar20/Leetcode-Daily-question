class Solution {
public:
    int maxLength(vector<string>& arr) {
        
        int n = arr.size();
        
        int pos = (1<<n);
        
        int mx = 0;
        
        for(int i=1;i<pos;i++)
        {
            vector<int> alp(26,0);
            bool ok=true;
            int cnt=0;
            for(int j=0;j<arr.size();j++)
            {
                if((i&(1<<j))!=0)
                {
                    cnt+=arr[j].size();
                    for(int k=0;k<arr[j].size();k++)
                    {
                        alp[arr[j][k]-'a']++;
                        
                        if(alp[arr[j][k]-'a']>1)
                        {
                            ok=false;
                            break;
                        }
                    }
                }
                if(!ok)
                    break;
            }
            if(ok)
                mx=max(mx,cnt);
        }
        
        return mx;
    }
};