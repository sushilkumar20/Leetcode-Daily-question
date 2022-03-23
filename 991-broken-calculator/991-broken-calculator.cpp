class Solution {
public:
    int brokenCalc(int startValue, int target) {
        
        int cnt=0;
        
        while(target>startValue)
        {
            cnt++;
            if(target%2==0)
             target=target/2;
            else
                target++;
        }
        
        cnt+=(startValue-target);
        
        return cnt;
    }
};