class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());
        
        int score =0;
        
        int i=0;
        int j=n-1;
        
        int ans=0;
        
        while(i<=j)
        {
            if(power>=tokens[i])
            {
                power-=tokens[i];
                i++;
                score++;
                ans=max(ans,score);
            }
            else
            {
                if(score>=1)
                {
                    score--;
                    power+=tokens[j];
                    j--;
                }
                else
                    break;
            }
        }
        
        return ans;
    }
};