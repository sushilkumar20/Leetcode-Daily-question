class Solution {
public:
    int minDeletions(string s) {
        
        vector<int> frequency(26,0);
        
        for(int i=0;i<s.size();i++)
        {
            frequency[s[i]-'a']++;
        }
        
        sort(frequency.rbegin(),frequency.rend());
        
        int deletecount =0 ;
        
        int maxFreqAllowed =s.size();
        
        for(int i=0;i<26&&frequency[i]>0;i++)
        {
            if(frequency[i]>maxFreqAllowed)
            {
                deletecount+=frequency[i]-maxFreqAllowed;
                frequency[i] = maxFreqAllowed;
            }
            
            maxFreqAllowed = max(0,frequency[i]-1);
        }
        
        return deletecount;
            
    }
};