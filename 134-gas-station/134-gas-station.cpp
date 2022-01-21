class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int tc=0;
        int tg=0;
        
        for(int i=0;i<gas.size();i++)
        {
            tc+=cost[i];
            tg+=gas[i];
        }
        
        if(tg<tc)
            return -1;
        
        int start=0;
        int tank=0;
        
        for(int i=0;i<gas.size();i++)
        {
            tank+=gas[i]-cost[i];
            
            if(tank<0)
            {
                start=i+1;
                tank=0;
            }
        }
        
        return start;
    }
};