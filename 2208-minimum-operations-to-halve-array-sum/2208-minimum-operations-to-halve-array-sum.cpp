class Solution {
public:
    int halveArray(vector<int>& nums) {
        
        priority_queue<double> pq;
        
        double sum =0;
        for(int i =0; i<nums.size();i++){
            sum+=nums[i];
            pq.push(nums[i]);
        }
        
        double k = sum;
       
        int cnt= 0;
        while(2.0*k>sum)
        {
           // k-=pq.top();
            double z = pq.top()/2.0;
           
            pq.pop();
            
            k-=z;
            pq.push(z);
            
            cnt++;
        }
        
        return cnt;
        
    }
};