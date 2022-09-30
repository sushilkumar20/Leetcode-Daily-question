class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        
       
        
        vector<int> ans;
        vector<int> hg(positions.size());
        for(int i=0;i<positions.size();i++)
        {
             int curr=positions[i][0];
             int ed = curr+positions[i][1];
            
            int mx=positions[i][1];
            for(int j=i-1;j>=0;j--)
            {
               
                 int x=positions[j][0];
                int y = x+positions[j][1];
                if((curr>x&&curr<y)||(ed>x&&ed<y))
                {
                    //cout<<curr<<" "<<ed<<" "<<x<<" "<<y<<endl;
                    mx=max(mx,hg[j]+positions[i][1]);
                }
                
                 if((x>curr&&x<ed)||(y>curr&&y<ed))
                {
                    //cout<<curr<<" "<<ed<<" "<<x<<" "<<y<<endl;
                    mx=max(mx,hg[j]+positions[i][1]);
                }
                
                 if(x==curr&&y==ed)
                {
                    //cout<<curr<<" "<<ed<<" "<<x<<" "<<y<<endl;
                    mx=max(mx,hg[j]+positions[i][1]);
                }
            }
        
            hg[i] = mx;
            
            mx=hg[i];
            for(int j=i;j>=0;j--)
            {
                mx=max(mx,hg[j]);
            }
            
            ans.push_back(mx);
        }
        
        return ans;
    }
};