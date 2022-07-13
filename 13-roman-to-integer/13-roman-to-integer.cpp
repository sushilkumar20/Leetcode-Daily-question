class Solution {
public:
    int romanToInt(string s) {
        
        map<string,int> mp;
        
        mp["I"] = 1;
        mp["V"] =5;
         mp["X"] =10;
         mp["L"] =50;
         mp["C"] =100;
         mp["D"] =500;
         mp["M"] =1000;
        
         mp["IV"] =4;
         mp["IX"] =9;
         mp["XL"] =40;
         mp["XC"] =90;
         mp["CD"] = 400;
         mp["CM"] = 900;
        
         int ans=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(i+1<s.size())
            {
                if(mp.find(s.substr(i,2))!=mp.end())
                {
                    ans+=mp[s.substr(i,2)];
                    i++;
                }
                else
                {
                    ans+=mp[s.substr(i,1)];
                }
            }
            else
                ans+=mp[s.substr(i,1)];
            
            //cout<<ans<<endl;
        }
        
        return ans;
    }
};