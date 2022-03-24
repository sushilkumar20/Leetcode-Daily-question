class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(),people.end());
        
        int i=0;
        int j=people.size()-1;
        
        int cnt=0;
        while(j>i)
        {
            if(people[i]+people[j]<=limit)
            {
                cnt++;
                i++;
                j--;
            }
            else
            {
                j--;
            }
        }
        
        return people.size()-cnt;
    }
};