class Solution {
public:
    int findNthDigit(int n) {
        long long start = 1, digitBit = 1, times = 9;
        while (n > digitBit * times)
        {
            n -= digitBit * times;
            digitBit++;
            times *= 10;
            start *= 10;
        }
        start += (n - 1) / digitBit;       
        string t = to_string(start);        
        return t[(n - 1) % digitBit] - '0'; 
       
    }
};