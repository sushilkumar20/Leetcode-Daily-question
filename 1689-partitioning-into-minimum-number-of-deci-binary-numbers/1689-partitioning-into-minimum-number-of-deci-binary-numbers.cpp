class Solution {
public:
    int minPartitions(string n) {
        
        sort(n.rbegin(),n.rend());
        return (int)(n[0]-'0');
    }
};