class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
       
      priority_queue<int> mxhp;
        
      priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> mnhp;
        
        int n = profits.size();
        
        for(int i=0;i<n;i++)
        {
            mnhp.push({capital[i],profits[i]});
        }
        
        while(k>0)
        {
            while(mnhp.size()&&mnhp.top()[0]<=w){
                mxhp.push({mnhp.top()[1]});
                mnhp.pop();
            }
            
            if(mxhp.size()==0)
                break;
           if(k>0&&mxhp.size())
            {
                w+=mxhp.top();
                mxhp.pop();
                k--;
            }
            
            if(k==0)
                break;
            
            
        }
        
        return w;
    }
};