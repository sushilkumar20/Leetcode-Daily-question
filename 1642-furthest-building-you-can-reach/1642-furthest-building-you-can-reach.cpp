class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int n=heights.size();
        priority_queue<int> pq;
        int cnt=0;
        for(int i=0;i<n-1;i++)
        {
            if(heights[i]>=heights[i+1])
                cnt++;
            else
            {
                int diff = heights[i+1]-heights[i];
                if(bricks>=diff){
                    bricks-=diff;
                    pq.push(diff);
                    cnt++;
                }
                else if(ladders)
                {
                    if(pq.size()&&pq.top()>diff)
                    {
                        bricks+=(pq.top()-diff);
                        pq.pop();
                        pq.push(diff);
                    }
                    ladders--;
                    cnt++;
                }
                else
                    break;
            }
        }
        
        return cnt;
        
    }
};