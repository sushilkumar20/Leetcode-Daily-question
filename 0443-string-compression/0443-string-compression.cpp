class Solution {
public:
    int compress(vector<char>& chars) {
        
        
        string ans = "";
        
        if(chars.size()==0)
            return 0;
        
        ans += chars[0];
        
        int curr = 1;
        
        vector<char> arr;
        arr.push_back(chars[0]);
        
        for(int i=1;i<chars.size();i++)
        {
            if(chars[i]==arr.back())
            {
                curr++;
            }
            else
            {
                if(curr>1)
                {
                   string x = to_string(curr);
                    
                    for(int j=0;j<x.size();j++)
                        arr.push_back(x[j]);
                }
                
               arr.push_back(chars[i]);
                curr=1;
            }
        }
        
        
                if(curr>1)
                {
                   string x = to_string(curr);
                    
                    for(int j=0;j<x.size();j++)
                        arr.push_back(x[j]);
                }
        
         // for(int i=0;i<arr.size();i++)
         // {
         //     cout<<arr[i]<<endl;
         // }
         //        cout<<arr.size()<<endl;
        chars = arr;
        
        return arr.size();
    }
};