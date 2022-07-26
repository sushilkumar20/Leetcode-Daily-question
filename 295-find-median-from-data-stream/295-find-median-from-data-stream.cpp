class MedianFinder {
public:
    
    priority_queue<int> mx;
    priority_queue<int,vector<int>,greater<int>> mn;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(mx.size() == mn.size())
        {
            if(mx.size()==0)
                mx.push(num);
            else
            {
                mn.push(num);
                mx.push(mn.top());
                mn.pop();
            }
        }
        else
        {
            mx.push(num);
            mn.push(mx.top());
            mx.pop();
        }
    }
    
    double findMedian() {
        
        if(mx.size()==mn.size())
        return double(mx.top()+mn.top())/2.0;
            
            return mx.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */