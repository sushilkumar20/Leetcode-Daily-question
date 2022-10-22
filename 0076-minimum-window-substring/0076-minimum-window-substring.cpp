class Solution {
public:
    string minWindow(string s, string t) {
        
        map<char,int> mp;
        
        for(int i=0;i<t.size();i++)
        {
            mp[t[i]]++;
        }
        
        int low = t.size();
        
        int high = s.size();
        string ans="";
       while(low<=high)
        {
        
           int mid = (low+high)/2;
             // cout<<low<<" "<<high<<endl;
            map<char,int> curr;
            
            for(int j=0;j<mid;j++)
                curr[s[j]]++;
            
            bool ok=true;
            
            for(auto i:mp)
            {
                if(i.second>curr[i.first])
                {
                    ok=false;
                    break;
                }
            }
            
            if(ok){
                 
                high=mid-1;
                if(ans.size()>mid||ans=="")
                ans = s.substr(0,mid);
                continue;
            }
            
           // cout<<s.substr(0,i)<<endl;
           int kk=0;
            for(int j=mid;j<s.size();j++)
            {
                curr[s[j-mid]]--;
                curr[s[j]]++;
                
                ok=true;
            
                for(auto i:mp)
                {
                    if(i.second>curr[i.first])
                    {
                        ok=false;
                        break;
                    }
                }

                if(ok){
                    kk++;
                    high=mid-1;
                    if(ans.size()>mid||ans=="")
                    ans = s.substr((j-mid+1),mid);
                    break;
                }
                
                 //cout<<s.substr(j-i+1,i)<<" "<<i<<endl;
                
            }
           if(!kk)
           low = mid+1;
        }
        
        return ans;
    }
};