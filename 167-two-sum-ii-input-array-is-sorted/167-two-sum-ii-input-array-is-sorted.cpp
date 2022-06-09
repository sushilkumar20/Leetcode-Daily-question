class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int> ans;
        
        int i = 0;
        int j = numbers.size()-1;
        
        while(i<j)
        {
            int sum = numbers[i]+numbers[j];
            
            if(sum==target)
            {
                return vector<int>{i+1,j+1};
            }
            else if(target>sum)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        
        return ans;
    }
};