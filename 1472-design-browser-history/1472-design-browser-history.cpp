class BrowserHistory {
public:
    
    vector<string> arr;
    int ind = 0;
    BrowserHistory(string homepage) {
        arr.push_back(homepage);
        ind++;
    }
    
    void visit(string url) {
       
        while(arr.size()>ind)
            arr.pop_back();
        
        arr.push_back(url);
        ind++;
    }
    
    string back(int steps) {
        
        ind = ind - steps;
        
        if(ind<=0)
            ind=1;
        
        return arr[ind-1];
    }
    
    string forward(int steps) {
        
        ind = ind + steps;
        
        if(ind>arr.size())
            ind=arr.size();
        
        return arr[ind-1];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */