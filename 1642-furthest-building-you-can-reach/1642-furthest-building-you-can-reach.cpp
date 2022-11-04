class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        priority_queue<int> pq;
        
        int dst = 0;
        int n = heights.size();
        
        for(int i=1;i<n;i++)
        {
            if(heights[i]>heights[i-1])
            {
                int diff = heights[i]-heights[i-1];
                // cout<<diff<<endl;
                if(bricks>=diff)
                {
                    pq.push(diff);
                    bricks-=diff;
                }
                else if(ladders>0)
                {
                    if(pq.size()>0&&pq.top()>diff)
                    {
                        bricks+=pq.top();
                        pq.pop();
                        pq.push(diff);
                        bricks-=diff;
                    }
                    
                    ladders--;
                }
                else
                    break;
            }
            
            
            dst++;
        }
        
        return dst;
    }
};