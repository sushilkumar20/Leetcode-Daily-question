class NumArray {
public:
    vector<int> seg;
    
    void build(int ind, int low, int high,vector<int>&nums)
    {
        if(low==high)
        {
            seg[ind] =  nums[low];
            return;
        }
        
        int mid = (low+high)/2;
        
        build(2*ind+1,low,mid,nums);
        build(2*ind+2,mid+1,high,nums);
        
         seg[ind] = seg[2*ind+1]+seg[2*ind+2];
    }
    
    int query(int ind, int low, int high, int l, int r)
    {
        if(low>=l&&high<=r)
        {
            return seg[ind];
        }
        
        if(high<l||low>r)
            return  0;
        
        int mid = (low+high)/2;
        int left = query(2*ind+1,low,mid,l,r);
        int right = query(2*ind+2,mid+1,high,l,r);
        
        return left+right;
    }
    
    void updateN(int ind, int low, int high, int node, int val)
    {
        if(low == high)
        {
            seg[ind] = val;
        }
        else
        {
            int mid = (low+high)/2;
            
            if(node<=mid&&node>=low)
            {
                updateN(2*ind+1,low,mid,node,val);
            }
            else
                updateN(2*ind+2,mid+1,high,node,val);
            
            seg[ind]= seg[ind*2+1]+seg[2*ind+2];
            
        }
    }
    
    vector<int> arr;
    NumArray(vector<int>& nums) {
        
        seg.resize(4*nums.size()+4);
        arr=nums;
        build(0,0,nums.size()-1,nums);
        
        //cout<<seg[0]<<endl;
    }
    
    void update(int index, int val) {
        updateN(0,0,arr.size()-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,arr.size()-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */