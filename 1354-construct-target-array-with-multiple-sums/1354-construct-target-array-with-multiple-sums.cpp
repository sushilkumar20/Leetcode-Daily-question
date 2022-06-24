class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        if(target.size()==1)
            return target[0]==1;
        long long sum=0;
        
        priority_queue<int> pq;
        
        for(int i=0;i<target.size();i++)
        {
            pq.push(target[i]);
            sum+=target[i];
        }
        
        while(pq.top()!=1)
        {
           int high = pq.top();
            
            if(sum-high == 1) return true;
            
            int x = high%(sum-high);
            
            sum = sum-high+x;
            pq.pop();
            
            if(x==0||x==high) return false;
            pq.push(x);
        }
        
        return true;
    }
};