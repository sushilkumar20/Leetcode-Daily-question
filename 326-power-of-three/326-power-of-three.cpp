class Solution {
public:
    bool isPowerOfThree(int n) {
        
        
      //  n = abs(n);
        
        if(n<=0)
            return false;
        
        int pw = float(log(n))/float(log(3));
        
        //cout<<pw<<endl;
        if(pow(3,pw)==n)
            return true;
        return false;
    }
};