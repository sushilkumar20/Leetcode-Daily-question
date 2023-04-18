class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string ans = "";
        int i=0;
        int j=0;
        
        while(i<word1.size() && j<word2.size())
        {
            ans += word1[i];
            ans += word2[j];
            i++;
            j++;
        }
        
        ans += word1.substr(i);
        ans += word2.substr(i);
        
        return ans;
    }
};