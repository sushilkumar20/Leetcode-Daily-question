class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int all=candies[0];
        
        for(int i=0;i<candies.size();i++)
        {
            all=max(all,candies[i]);
        }
        vector<bool> arr;
        for(int i=0;i<candies.size();i++)
        {
            if(candies[i]+extraCandies>=all)
                arr.push_back(true);
            else
                arr.push_back(false);
        }
        
        return arr;
    }
};