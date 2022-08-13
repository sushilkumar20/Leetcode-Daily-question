class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        map<string,int> st;
        int window=0;
        int sm =0;
        for(int i=0;i<words.size();i++)
        {
            sm=words[i].size();
            window+=words[i].size();
            st[words[i]]++;
        }
       //cout<<window<<" "<<s.size()<<endl;
        if((int)s.size()-window<0)
            return ans;
        for(int i=0;i<=s.size()-window;i++)
        {
            string p = s.substr(i,window);
            map<string,int> mp;
            for(int j=0;j<p.size();j+=sm)
            {
                mp[p.substr(j,sm)]++;
            }
            bool ok=true;
            for(auto j:st)
            {
                if(j.second!=mp[j.first])
                {
                    ok=false;
                    break;
                }
            }
            
            if(ok)
                ans.push_back(i);
        }
        
        return ans;
    }
};