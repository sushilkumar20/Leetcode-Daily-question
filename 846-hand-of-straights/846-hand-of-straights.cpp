class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        sort(hand.begin(),hand.end());
        map<int,int> mp;
        
        for(int i=0;i<hand.size();i++)
            mp[hand[i]]++;
        
        for(int i=0;i<hand.size();i++)
        {
            if(mp[hand[i]]==0)
                continue;
            
            int x=hand[i];
            
            for(int j=0;j<groupSize;j++)
            {
                if(mp[x]==0)
                    return false;
                
                mp[x]--;
                x++;
            }
        }
        
        return true;
    }
};