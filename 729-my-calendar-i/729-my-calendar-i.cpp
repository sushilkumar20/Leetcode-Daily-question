class MyCalendar {
public:
    
    vector<pair<int,int>> vp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
         
       if(vp.size()==0)
       {
           vp.push_back({start,end});
           return true;
       }
        
        for(int i=0;i<vp.size();i++)
        {
            if(start>vp[i].first&&start<vp[i].second)
                return false;
           if(end>vp[i].first&&end<vp[i].second)
                return false;
            
            if(start<=vp[i].first&&end>=vp[i].second)
                return false;
        }
        
        vp.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */