class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        vector<string> st={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        map<string,int> mp;
        string k="";
        
        for(int i=0;i<words.size();i++)
        {
            k="";
            for(int j=0;j<words[i].size();j++)
            {
                k+=st[words[i][j]-'a'];
            }
            mp[k]++;
        }
        return mp.size();
    }
};