/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    
    Node *help(int i,int j, int n, vector<vector<int>> &grid)
    {
        set<int> st;
        
        // cout<<i+n<<" "<<j+n<<endl;
        for(int x=i;x<=i+n;x++)
        {
            for(int y=j;y<=j+n;y++)
            {
                st.insert(grid[x][y]);
            }
        }
        
        // cout<<st.size()<<endl;
        if(st.size()==1)
        {
            Node *node = new Node(*st.begin(),1);
            
            return node;
        }
        else
        {
            Node *node = new Node(*st.begin(),0);
            
            node->topLeft = help(i,j,(n-1)/2,grid);
            node->topRight = help(i,j+(n-1)/2+1,(n-1)/2,grid);
            node->bottomLeft = help(i+(n-1)/2+1,j,(n-1)/2,grid);
            node->bottomRight = help(i+(n-1)/2+1,j+(n-1)/2+1,(n-1)/2,grid);
            
            return node;
        }
    }
    Node* construct(vector<vector<int>>& grid) {
        
        return help(0,0,grid.size()-1,grid);
    }
};