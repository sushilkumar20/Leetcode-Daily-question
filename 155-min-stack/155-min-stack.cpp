class MinStack {
public:
    
    stack<long long> st;
    long long mn;
    MinStack() {
        mn=1e10;
    }
    
    void push(int val) {
       
        if(st.size()==0)
        {
            mn=val;
            st.push(val);
        }
        else
        {
            if(val>=mn)
            {
                st.push(val);
            }
            else
            {
                long long modified = 2ll*val - mn;
                st.push(modified);
                mn = val;
            }
                
        }
    }
    
    void pop() {
        if(st.top()>=mn)
        {
            st.pop();
        }
        else
        {
            long long modified = st.top();
            st.pop();
            mn = 2*mn-modified;
        }
    }
    
    int top() {
        if(st.top()>=mn)
            return st.top();
       return mn;
        
    }
    
    int getMin() {
        
       return mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */