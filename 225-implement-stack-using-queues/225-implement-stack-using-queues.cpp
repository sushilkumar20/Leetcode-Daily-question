class MyStack {
public:
    /** Initialize your data structure here. */
    
    queue<int> q1;
    
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        
        int count=0;
        while(count<q1.size()-1)
        {
            count++;
            q1.push(q1.front());
            q1.pop();
        }
        
        int ans=q1.front();
        q1.pop();
        
        
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        
        int count=0;
        while(count<q1.size()-1)
        {
            count++;
            q1.push(q1.front());
            q1.pop();
        }
        
        int ans=q1.front();
        q1.push(ans);
        q1.pop();
     
        
        
        return ans;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(q1.size()==0)
            return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */